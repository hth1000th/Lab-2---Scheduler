#include <stdio.h>
#include "queue.h"
#include "scheduler.h"

int stop() {
  int stopped_pid;
  if(running_process > 0) {
    stopped_pid = running_process;
    running_process = 0;
    return stopped_pid;
  }
  else {
    return 0;
  }
}

void ready(int pid) {
  enqueue(ready_qu, pid);
}

void sleep(int abs_time) {
  int pid = stop();
  int target_time = global_clock + abs_time;
  enqueue(timed_qu, pid);
  timed_qu->tail->target_time = target_time;
  if(!is_empty(ready_qu)) {
    run_next();
  }
}

void awaken() {
  int pid = dequeue(timed_qu);
  ready(pid);
}

void block() {
  int i = 0;
  int pid = stop();
  while(io_list[i] > 0) {
    i++;
  }
  io_list[i] = pid;
  io_list[i+1] = 0;
  if(!is_empty(ready_qu)) {
    run_next();
  }
}

int run_next() {
  running_process = dequeue(ready_qu);
  return running_process;
}

void tick() {
  global_clock++;
  while(check_awaken()) {
    awaken();
    if(timed_qu->head == NULL) {
      break;
    }
  }
}

int check_awaken() {
  return global_clock == timed_qu->head->target_time;
}
