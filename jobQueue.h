

#ifndef CGIT_JOBQUEUE_H
#define CGIT_JOBQUEUE_H

typedef struct Job {
    int priority;
    char description[255];
} job_t ;

typedef struct QueueEl {
    job_t job;
    struct QueueEl *next;
} QueueEl_t ;

typedef struct JobQueue {
    int count;
    struct QueueEl *first, *last;
} JobQueue_t ;

int pushJQ (JobQueue_t *pJQ, const job_t *pJob);

job_t popJQ (JobQueue_t *pJQ);

void printJQ (JobQueue_t *pJQ);

int readFromFile(JobQueue_t *pJQ);

int writeToFile(JobQueue_t *pJQ);

#endif //CGIT_JOBQUEUE_H

