#include <stdio.h>
#include "jobQueue.h"


int main() {
    JobQueue_t queue1 = {0};
    JobQueue_t queue2 = {0};
    job_t arbeitslos = {
            1,
            "Arbeitlos"
    };
    job_t prof = {
            10,
            "Professor"
    };
    job_t student = {
            1000,
            "Student"
    };
    job_t businessman = {
            12,
            "Geschäftsmann"
    };
    pushJQ(&queue1, &businessman);
    pushJQ(&queue2, &student);
    pushJQ(&queue1, &prof);
    job_t a = popJQ(&queue1);
    pushJQ(&queue2, &a);
    printJQ(&queue1);
    printJQ(&queue2);
}
