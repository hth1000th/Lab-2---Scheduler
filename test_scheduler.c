#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "queue.h"
#include "scheduler.h"
#include <test_scheduler.h>

Queue *qu;
int main(void) {
  qu = create();

  test_running();
  test_stop();
  test_ready();
  test_sleep();
  test_awaken();
  test_block();
  test_run_next();
  delete(qu);

  puts("testing complete");
  return 0;
}

void test_running() {
  puts("testing int running(Queue *ready)");
  enqueue(qu, 123);
  enqueue(qu, 0);
  enqueue(qu, -45);
  assert(running(qu) == 123);
  assert(running(qu) == 0);
  assert(running(qu) == -45);
}

void test_stop() {
  puts("testing int stop(int current_pid)");
  assert(stop(84) == 84);
  assert(stop(392) == 392);
  assert(stop(0) == -1);
  assert(stop(-71) == -71);
}

void test_ready() {
  puts("testing void ready(Queue *ready, int pid)");
  ready(qu, 222);
  assert(qu->tail->pid == 222 && qu->size == 1);
  ready(qu, -98);
  assert(qu->tail->pid == -98 && qu->size == 2);
  ready(qu, 0);
  assert(qu->tail->pid == 0 && qu->size == 3);
  ready(qu, 2.5);
  assert(qu->tail->pid == 2 && qu->size == 4);
}

void test_sleep() {
  puts("testing void sleep(int pid, int abs_time)");
}

void test_awaken() {
  puts("testing void awaken(int pid)");
}

void test_block() {
  puts("testing void block(int pid)");
}

void test_run_next() {
  puts("testing int run_next()");
}
