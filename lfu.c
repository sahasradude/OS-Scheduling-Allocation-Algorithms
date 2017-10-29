#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
int main() {
    int len;
    int arr[128];
    int count[10];
    int hash[10];
    int i, j, inplen, min = INT_MAX;
    int index;
    int pf;
    int * frame;
    for (i = 0; i < 10; i++) {
        count[i] = 0;
        hash[i] = 0;
    }
    printf("Enter the frame size\n"); 
    scanf("%d", &len);
    printf("Enter the reference string\n");
    inplen = 0;
    while(scanf("%d", &arr[inplen])!= EOF){
        inplen++;
    }
    pf = 0;
    frame = (int *) malloc(sizeof(int) * len);
    for(i = 0; i<inplen; i++) {
        printf("\n"); 
        count[arr[i]]++;
        if(hash[arr[i]] == 0) {
            if(pf < len) {
                frame[pf] = arr[i];
            }
            else{
                for(j = 0; j < len; j++) {
                    if(count[frame[j]] < min) {
                        min = count[frame[j]];
                        index = j;
                    }
                }
                hash[frame[index]] = 0;
                frame[index] = arr[i];
                min = INT_MAX; 
            }
            hash[arr[i]] = 1;
            pf++;
        }
        for(j = 0; j <  (pf  < len ? pf : len); j++) {
            printf("| %d | count: %d\n", frame[j], count[frame[j]]); 
        }
        printf("page faults: %d\n", pf);
    }
    return 0;
}
