typedef struct queue *Queue;
typedef struct process Process;
Queue create();
void delete(Queue qu);
void enqueue(Queue qu, int pid);
int dequeue(Queue qu);
int peek(Queue qu);
