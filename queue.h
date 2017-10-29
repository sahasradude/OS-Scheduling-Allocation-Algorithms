typedef struct queue {
    int *arr;
    int length;
    int maxlen;
}queue;
int dequeue(queue *q);
void enqueue(queue *q, int x);
void qinit(queue * q, int len);
int qfull(queue *q);
int qempty(queue *q);
int qlen(queue *q);
void printq(queue *q);
