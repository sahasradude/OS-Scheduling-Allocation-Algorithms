#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"
int main() {
    int len;
    int arr[128];
    int hash[10];
    int i, inplen;
    int pf;
    int x;
    for (i = 0; i < 10; i++) {
        hash[i] = 0;
    }
    printf("Enter the frame size\n"); 
    scanf("%d", &len);
    printf("Enter the reference string\n");
    inplen = 0;
    while(scanf("%d", &arr[inplen])!= EOF){
        inplen++;
    }
    queue q;
    qinit(&q, len);
    pf = 0;
    for(i = 0; i<inplen; i++) {
        printf("\n"); 
        if(hash[arr[i]] == 0) {
            if(!qfull(&q)) {
                printf("Put in queue: %d\n", arr[i]); 
                enqueue(&q, arr[i]);
                hash[arr[i]] = 1;
                pf++;
            }
            else {
                x = dequeue(&q);
                printf("Removed from queue: %d\n", x); 
                hash[x] = 0;
                printf("Put in queue: %d\n", arr[i]); 
                enqueue(&q, arr[i]);
                hash[arr[i]] = 1;
                pf++;
            }
            printq(&q);
            printf("Page faults: %d\n", pf); 
        }
    }
    return 0;
}
