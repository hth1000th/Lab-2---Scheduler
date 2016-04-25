#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <queue.h>
#include <test_queue.h>

int main(void) {

  test_create();
  test_delete();
  test_is_empty();
  test_enqueue();
  test_dequeue();
  test_peek();

  puts("testing complete");
  return 0;
}

void test_create() {
  puts("testing Queue create()");
}

void test_delete() {
  puts("testing void delete(Queue qu)");
}

void test_is_empty() {
  puts("testing int is_empty(Queue qu)");
}

void test_enqueue() {
  puts("testing void enqueue(Queue qu, int pid)");
}

void test_dequeue() {
  puts("testing int dequeue(Queue qu)");
}

void test_peek() {
  puts("testing int peek(Queue qu)");
}
