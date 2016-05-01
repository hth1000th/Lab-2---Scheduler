Queue *ready_qu;
Queue *timed_qu;
int io_list[50];
int running_process;
int global_clock;

// stop the current running process if it exitsts, return its pid
int stop();
 // enqueue pid to ready queue;
void ready(int pid);
// stop(), calculate absolute time from relative time, add pid to wait list,
// run_next()
void sleep(int abs_time);
// remove from wait list, ready;
void awaken();
void block();
// stop(), add pid to I/O list, run_next();
// dequeue the next process from the ready queue, ready()
// previous process if it exists;
int run_next();
void tick();
int check_awaken() ;
