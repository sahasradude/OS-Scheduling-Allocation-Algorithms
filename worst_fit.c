#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define MEM_MAX 128
typedef struct area {
    int freelen;
    int usedlen;
    int index;
}area;

char memory[MEM_MAX]; //each index is 1k of memory
/*declaring heap globally so that we do not need to pass it as an argument every time*/
/* Heap used here is Min Heap */
area heap[MEM_MAX/2 + 2];
int heapSize;
/*initialize Heap*/
void init()
{
    heapSize = 0;
    return;
}
/*insert an element into the heap */
void insert(area element) {
    /*if(heapSize == 0) {
        heap[0] = element;
    }*/
    heapSize++;
    heap[heapSize] = element; /*insert in the last place*/
    /*Adjust its position*/
    int now = heapSize;
    while(heap[now/2].freelen < element.freelen && now > 1) 
    {
        heap[now] = heap[now/2];
        now /= 2;
    }
    heap[now] = element;
    return;
}
area deletemin() {
    /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased. 
       Now heap[1] has to be filled. We put the last element in its place and see if it fits.
       if it does not fit, take minimum element among both its children and replaces parent with it.
       Again See if the last element fits in that place.*/
    area minElement,lastElement;
    int now, child;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    /* now refers to the index at which we are now */
    for(now = 1; now*2 <= heapSize ;now = child)
    {
        /* child is the index of the element which is minimum among both the children */ 
        /* indexes of children are i*2 and i*2 + 1*/
        child = now*2;
        /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one 
          child */
        if(child != heapSize && heap[child+1].freelen > heap[child].freelen ) 
        {
            child++;
        }
        /* To check if the last element fits ot not it suffices to check if the last element
           is less than the minimum element among both the children*/
        if(lastElement.freelen < heap[child].freelen)
        {
            heap[now] = heap[child];
        }
        else /* it fits there */
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}

void createmem() { //creates randomised memory with roughly 1/8th of the blocks filled, and the rest empty
    int i = 0;
    srand(time(NULL));
    printf("%d\n%d\n%d\n", rand(), rand(), RAND_MAX); 
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
    /*for(i = 0; i < MEM_MAX; i++) {
      printf("%d", memory[i]); 
      }
      printf("\n"); */
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

    init();
    for(i = 0; i < length; i++) {
        insert(arr[i]); 
        /*for(j = 1; j <= heapSize; j++) {
            printf("[%d free][%d used]", heap[j].freelen, heap[j].usedlen);
        }
        printf("\n");*/
    }

    while(1) {
        printf("Enter the size of the block you want allocated\n");
        scanf("%d", &newelem);
        area a;
        a = deletemin();
        if(a.freelen >= newelem) {
            a.freelen = a.freelen - newelem;
            a.usedlen = a.usedlen + newelem;
            insert(a);
        }
        else {
            printf("Block is too large\n");
            insert(a);
        }
        int indexcount = 0;
        while(indexcount < length) {
            for(i = 1; i <= heapSize; i++){
                if(indexcount == heap[i].index) {
                    printf("[%d free][%d used]", heap[i].freelen, heap[i].usedlen);
                    indexcount++;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
