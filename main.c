#include <stdio.h>
#include "jobQueue.h"

int fac(int i) {
    if (i == 1) {
        return 1;
    }
    return i + fac(i-1);
}


int main() {
    JobQueue_t queue1 = {0};
    JobQueue_t queue2 = {0};
    readFromFile(&queue1);
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
    writeToFile(&queue1);
    return 0;
}
