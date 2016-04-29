#include <stdio.h>
#include "queue.h"
#include "scheduler.h"

int running(Queue *ready) {
  int current_pid = run_next(ready);
  return current_pid;
}

int stop(int current_pid) {
  if(current_pid != 0) {
    return current_pid;
  }
  else {
    return -1;
  }
}

void ready(Queue *ready, int pid) {
  enqueue(ready, pid);
}

void sleep(int pid, int abs_time) {
  stop(pid);
  enqueue(timed_wait, pid);

}

void awaken(int pid) {
}

void block(int pid) {
}

int run_next(Queue *ready) {
  int next_pid = dequeue(ready);
  return next_pid;
}
