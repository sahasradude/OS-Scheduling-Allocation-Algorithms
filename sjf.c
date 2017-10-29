#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a, b) (a > b ? a : b)
typedef struct table {
    int arrival;
    int execute;
}table;
int cmpfunc (const void * p, const void * q){
    return (int)((table *) p)->execute - ((table *) q)->execute;
}
int main() {
    printf("Enter the arrival time and the execution time of each process\n");
    int i = 0, tablen = 0;
    int service = 0, wait = 0, tot_wait = 0;
    table t[32];
    while(scanf("%d%d", &t[tablen].arrival, &t[tablen].execute) != EOF) {
        tablen++;
    }
    qsort((void *)t, tablen, sizeof(table), cmpfunc);
    service = 0;
    printf("P0:\narrival time: %d execute time: %d service time: %d wait time: %d\n", t[0].arrival, t[0].execute, service, wait); 
    for(i = 1; i < tablen; i++){
        service = service + t[i - 1].execute;
        if(service - t[i].arrival > 0)
            wait = service - t[i].arrival;
        else
            wait = 0;
        tot_wait+= wait;
        printf("P%d:\narrival time: %d execute time: %d service time: %d wait time: %d\n", i,t[i].arrival, t[i].execute, service, wait); 
    }
    printf("average wait time: %f\n", ((float)tot_wait/(float)tablen)); 
    return 0;
}
