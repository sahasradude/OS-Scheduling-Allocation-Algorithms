#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a, b) (a > b ? a : b)
typedef struct table {
    int arrival;
    int execute;
    int priority;
}table;
int cmpfunc (const void * p, const void * q){
    int x = (int) ((table *) q)->priority - ((table *) p)->priority;
    if (x != 0)
        return x;
    else
        return (int) ((table *) p)->arrival - ((table *) q)->arrival;
}
int main() {
    printf("Enter the arrival time, execution time, and priority of each process\n");
    int i = 0, tablen = 0;
    int service = 0, wait = 0, tot_wait = 0;
    table t[32];
    while(scanf("%d%d%d", &t[tablen].arrival, &t[tablen].execute, &t[tablen].priority) != EOF) {
        tablen++;
    }
    qsort((void *)t, tablen, sizeof(table), cmpfunc);
    service = 0;
    printf("P0:\npriority: %d arrival time: %d execute time: %d service time: %d wait time: %d\n",t[0].priority, t[0].arrival, t[0].execute, service, wait); 
    for(i = 1; i < tablen; i++){
        service = service + t[i - 1].execute;
        if(service - t[i].arrival > 0)
            wait = service - t[i].arrival;
        else
            wait = 0;
        tot_wait+= wait;
        printf("P%d:\npriority: %d arrival time: %d execute time: %d service time: %d wait time: %d\n", i, t[i].priority, t[i].arrival, t[i].execute, service, wait); 
    }
    printf("average wait time: %f\n", ((float)tot_wait/(float)tablen)); 
    return 0;
}
