#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
int dist[10];
int find(int *refstr, int *frame, int elem, int inplen, int flen) {
    int i, j;
    int count = 0;
    int distmax = -1;
    int index = 0;
    for(i = 0; i < flen; i++) {
        for(j = elem + 1; j < inplen; j++) {
            if(frame[i] == refstr[j]) {
                dist[frame[i]] = j - elem;
                if(dist[frame[i]] > distmax) {
                    distmax = dist[frame[i]];
                    index = i;
                }
                count++;
                break;
            }
        }
        if (count == 0) {
            dist[frame[i]] = INT_MAX;
            return i;
        }
        count = 0;
    }
    return index;
}
int main() {
    int flen;
    int arr[128];
    int hash[10];
    int i, inplen, j;
    int pf;
    int x;
    for (i = 0; i < 10; i++) {
        hash[i] = 0;
        dist[i] = INT_MAX;
    }
    printf("OPTIMAL:\nEnter the frame size\n"); 
    scanf("%d", &flen);
    printf("Enter the reference string\n");
    inplen = 0;
    while(scanf("%d", &arr[inplen])!= EOF){
        inplen++;
    }
    pf = 0;
    int fnext = 0;
    int * frame = (int *) malloc ((sizeof(int)) * flen);
    for(i = 0; i<inplen; i++) {
        if(hash[arr[i]] == 0) {
            printf("\n"); 
            if(pf < flen) {
                printf("Put in frame: %d\n", arr[i]); 
                frame[pf] = arr[i];
                hash[arr[i]] = 1;
                pf++;
            }
            else {
                fnext = find(arr, frame, i, inplen, flen);
                x = frame[fnext];
                printf("Removed from frame: %d\n", x); 
                hash[x] = 0;
                printf("Put in frame: %d\n", arr[i]); 
                frame[fnext] = arr[i];
                hash[arr[i]] = 1;
                pf++;
            }
            for(j = 0; j < (pf < flen ? pf : flen); j++){
                printf("| %d |\n", frame[j]); 
            }
            printf("Page faults: %d\n", pf); 
        }
    }
    return 0;
}
