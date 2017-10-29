#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int dequeue(queue * q) {
    if(qempty(q)) {
        return INT_MIN;
    }
    int x = q->arr[0];
    int i;
    for(i = 1; i < q->length; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->length--;
    return x;
}
void enqueue(queue * q, int x) {
    if(!qfull(q)) {
        q->arr[q->length] = x;
        (q->length)++;
    }
}
void qinit(queue *q, int len) {
    q->length = 0;
    q->arr = (int *) malloc(sizeof(int)*len + 2);
    q->maxlen = len;
}
int qfull(queue *q) {
    return q->length == q->maxlen;
}
int qempty(queue * q) {
    return q->length == 0;
}
int qlen(queue *q) {
    return q->length;
}
void printq(queue * q) {
    printf("\nFRAME:\n");
    int i;  
    for(i = 0; i < q->length; i++) {
        printf("| %d |\n",q->arr[i]); 
    }
}
