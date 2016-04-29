int running(Queue *ready);
int stop(int current_pid); // stop the current running process if it exitsts, return its pid
void ready(Queue *ready, int pid); // enqueue pid to ready queue;
// stop(), calculate absolute time from relative time, add pid to wait list,
// run_next()
void sleep(int pid, int abs_time);
void awaken(int pid); // remove from wait list, ready;
void block(int pid); // stop(), add pid to I/O list, run_next();
// dequeue the next process from the ready queue, ready()
// previous process if it exists;
int run_next();
