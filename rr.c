#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a, b) (a > b ? a : b)
typedef struct table {
    int arrival;
    int execute;
    int service;
    int wait;
}table;
int main() {
    int quant, count;
    int i = 0, tablen = 0;
    int service = 0, wait = 0, tot_wait = 0;
    table t[32];
    int hash[10];
    for(i = 0; i < 10; i++)
        hash[i] = 0;
    printf("Enter the time quantum\n");
    scanf("%d", &quant);  
    printf("Enter the arrival time and the execution time of each process\n");
    while(scanf("%d%d", &t[tablen].arrival, &t[tablen].execute) != EOF) {
        t[tablen].service = 0;
        t[tablen].wait = t[tablen].arrival;
        tablen++;
    }
    while(1) {
        count = 0;
        for(i = 0; i < tablen; i++) {
            if(hash[i] == 1)
                continue;
            if(t[i].execute - quant > 0) {
                t[i].execute = t[i].execute - quant;
                t[i].service = service;
                service = service + quant;
                count++;     
            }
            else {
                t[i].service = service;
                service += t[i].execute; 
                t[i].execute = 0;
                hash[i] = 1;
            }
            t[i].wait = (t[i].service - t[i].wait); 
            printf("P%d:\narrival time: %d execution time: %d service time: %d wait time: %d\n", i, t[i].arrival, t[i].execute, t[i].service, t[i].wait);
        }
        if(count == 0)
            break;
    }
    for(i = 0; i < tablen; i++){
        printf("P%d: waiting time:%d\n", i,t[i].wait); 
        tot_wait += t[i].wait;
    }
    printf("average wait time: %f\n", ((float)tot_wait/(float)tablen)); 
    return 0;
}
