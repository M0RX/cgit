#include <stdio.h>
#include <stdlib.h>
#include "jobQueue.h"

int pushJQ (JobQueue_t *pJQ, const job_t *pJob) {


    QueueEl_t * newElement = calloc(1, sizeof(QueueEl_t));
    if (newElement == NULL) {
        return 0;
    }

    newElement->job = *pJob;

    if (++ pJQ->count == 1) {
        pJQ->first = pJQ->last = newElement;
    } else {
        QueueEl_t * q = pJQ->first;
        QueueEl_t * prev = NULL;
        for ( ; (prev == pJQ->last) && (q->job.priority < newElement->job.priority); q = q->next) {
            prev = q;
        }
        if (prev == NULL) {
            newElement->next = pJQ->first;
            pJQ->first = newElement;
        } else {
            newElement->next = q;
            prev->next = newElement;
            if (prev == pJQ->last) {
                pJQ->last = newElement;
            }
        }
    }
    return 1;
}

job_t popJQ (JobQueue_t *pJQ) {
    job_t result = {0};

    if (pJQ->first != NULL) {
        QueueEl_t *element = pJQ->first;
        result = element->job;
        if (-- pJQ->count == 0) {
            pJQ->first = pJQ->last = NULL;
        } else {
            pJQ->first = pJQ->first->next;
        }
        free(element);
    }

    return result;
}

void printJQ (JobQueue_t *pJQ) {
    if (pJQ->first == NULL) {
        printf("Es sind keine Elemente in der Schlange enthalten\n");
    } else {
        QueueEl_t * q = pJQ->first;
        for ( ; q != NULL; q = q->next) {
            printf("Element: %s  und Priorität %d\n", q->job.description, q->job.priority);
            printf("|\n");
            printf("v\n");
        }
    }

}
