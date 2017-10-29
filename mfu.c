#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int len;
    int arr[128];
    int count[10];
    int hash[10];
    int i, j, inplen, max = -1;
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
        if(hash[arr[i]] == 0) {
            if(pf < len) {
                frame[pf] = arr[i];
            }
            else{
                for(j = 0; j < len; j++) {
                    if(count[frame[j]] > max) {
                        max = count[frame[j]];
                        index = j;
                    }
                }
                hash[frame[index]] = 0;
                frame[index] = arr[i];
                max = -1; 
            }
            hash[arr[i]] = 1;
            pf++;
            for(j = 0; j <  (pf  < len ? pf : len); j++) {
                printf("| %d |\n", frame[j]); 
            }
            printf("page faults: %d\n", pf);
        }
        count[arr[i]]++;
    }
    return 0;
}
