#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "queue.h"
#include "scheduler.h"
#include <test_scheduler.h>

int main(void) {
  ready_qu = create();
  timed_qu = create();
  io_list[0] = 0;
  global_clock = 0;

  test_stop();
  test_ready();
  test_sleep();
  test_awaken();
  test_block();
  test_run_next();
  test_tick();
  test_check_awaken();

  delete(ready_qu);
  delete(timed_qu);

  puts("testing complete");
  return 0;
}

void test_stop() {
  enqueue(ready_qu, 84);
  enqueue(ready_qu, -12);
  enqueue(ready_qu, 0);
  puts("testing int stop()");
  run_next();
  assert(stop() == 84);
  run_next();
  assert(stop() == 0);
  run_next();
  assert(stop() == 0);
}

void test_ready() {
  puts("testing void ready(int pid)");
  ready(222);
  assert(ready_qu->tail->pid == 222 && ready_qu->size == 1);
  ready(-98);
  assert(ready_qu->tail->pid == -98 && ready_qu->size == 2);
  ready(0);
  assert(ready_qu->tail->pid == 0 && ready_qu->size == 3);
  ready(2.5);
  assert(ready_qu->tail->pid == 2 && ready_qu->size == 4);
  delete(ready_qu);
}

void test_sleep() {
  ready_qu = create();
  enqueue(ready_qu, 77);
  enqueue(ready_qu, 34);
  enqueue(ready_qu, 92);
  puts("testing void sleep(int abs_time)");
  run_next();
  sleep(2);
  assert(timed_qu->tail->pid == 77 && timed_qu->tail->target_time == 2);
  sleep(10);
  assert(timed_qu->tail->pid == 34 && timed_qu->tail->target_time == 10);
  sleep(23);
  assert(timed_qu->tail->pid == 92 && timed_qu->tail->target_time == 23);
}

void test_awaken() {
  puts("testing void awaken()");
  awaken();
  assert(timed_qu->head->pid == 34 && ready_qu->tail->pid == 77);
  awaken();
  assert(timed_qu->head->pid == 92 && ready_qu->tail->pid == 34);
  awaken();
  assert(timed_qu->head == NULL && ready_qu->tail->pid == 92);
}

void test_block() {
  puts("testing void block()");
  running_process = 112;
  block();
  assert(io_list[0] == 112);
  running_process = 0;
  block();
  assert(io_list[0] == 112 && io_list[1] == 0);
  running_process = -23;
  block();
  assert(io_list[0] == 112 && io_list[1] == 0);
}

void test_run_next() {
  enqueue(ready_qu, 54);
  enqueue(ready_qu, 234);
  enqueue(ready_qu, 7);
  puts("testing int run_next()");
  assert(run_next() == 54);
  assert(run_next() == 234);
  assert(run_next() == 7);
}

void test_tick() {
  ready(85);
  ready(392);
  ready(6);
  puts("testing void tick()");
  sleep(1);
  tick();
  assert(global_clock == 1 && timed_qu->tail == NULL);
  sleep(8);
  tick();
  assert(global_clock == 2 && timed_qu->tail->pid == 85);
  sleep(10);
  tick();
  assert(global_clock == 3 && timed_qu->tail->pid == 392);
  sleep(12);
  tick();
  assert(global_clock == 4 && timed_qu->tail->pid == 6);
}

void test_check_awaken() {
  puts("testing int check_awaken()");
  assert(check_awaken() == 0);
  global_clock = 9;
  assert(check_awaken() == 1);
  global_clock = 11;
  assert(check_awaken() == 0);
}
