#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MEM_MAX 128
typedef struct area {
    int freelen;
    int usedlen;
    int index;
}area;

char memory[MEM_MAX]; //each index is 1k of memory

void createmem() { //creates randomised memory with roughly 1/8th of the blocks filled, and the rest empty
    int i = 0;
    while(i < MEM_MAX) {
        if (rand()/(RAND_MAX/8) == 0) {
            memory[i] = 1;
            i++;
            if ((rand()/(RAND_MAX/4) == 0) && i < MEM_MAX) {
                memory[i] = 1;
                i++;
                if ((rand()/(RAND_MAX/2) == 0) && i < MEM_MAX) {
                    memory[i] = 1;
                    i++;
                }
            }
        }

        else {
            memory[i] = 0;
            i++;
        }
    }
}
int main() {
    createmem();
    int i;
    int newelem;
    area arr[MEM_MAX/2 + 2];
    int length = 0;
    int usedcount = 0, freecount = 0; 
    char on_one = memory[0];
    for(i = 0; i < MEM_MAX; i++) {
        if ((memory[i] == 0) && (on_one == 0)) {
            freecount++;
        }
        else if((memory[i] == 1)) {
            usedcount++;
            on_one = 1;
        }
        if(((memory[i] == 0) && (on_one == 1)) || (i == (MEM_MAX - 1))) {
            arr[length].freelen = freecount;
            arr[length].usedlen = usedcount;
            arr[length].index = length;
            length++;
            freecount = 1;
            usedcount = 0;
            on_one = 0;
        }
    }
    int lastall = 0;
    while(1) {
    	i = lastall;
        printf("Enter the size of the block you want allocated\n");
        scanf("%d", &newelem);
        /*if(newelem > arr[length - 1].freelen){
            printf("Block is too large\n");
            continue;  
        }*/
        while(arr[i%(length)].freelen < newelem)
        	i++;
        lastall = i+1;
        arr[i%(length)].freelen = arr[i%(length)].freelen - newelem;
        arr[i%(length)].usedlen = arr[i%(length)].usedlen + newelem;
            for(i = 0; i < length; i++){
                    printf("[%d free][%d used]", arr[i].freelen, arr[i].usedlen);
            }
        printf("\n");
    }
    return 0;
}
