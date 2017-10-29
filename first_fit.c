#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#define TOT_MEM 62
long fit(long memory, int block) {
    long searcher = (1UL << block) - 1;
    while((searcher & (1UL << TOT_MEM)) == 0UL) {
        if ((searcher & memory) == 0UL) {
            memory = searcher | memory;
            return memory;
        }
        else
            searcher = searcher << 1;
    }
    printf("Block too large for memory, please try again\n");
    return memory;
}
void printmem(long memory) {
    long searcher = 1;
    char on_one = memory % 2;
    int storecount = 0;
    int freecount = 0;
    printf("MEMORY:\n"); 
    while((searcher & (1UL << TOT_MEM)) != (1UL << TOT_MEM)) {
        if((searcher & memory) == searcher) {
            if (on_one == 0) {
                printf("|%dk free| ", freecount);
                freecount = 0; 
                on_one = 1;
            }
            storecount++;
        }
        else if((searcher & memory) == 0) {
            if(on_one == 1) {
                printf("[%dk used] ", storecount);
                storecount = 0;
                on_one = 0;
            }
            freecount++;
        }
        searcher = searcher << 1;
    }
    printf("\n"); 

}
int main() {
    long memory = 2253458177687809;  //1000000000011000001000011110001100101000000100000001 in decimal
    //every binary digit is 1k worth of memory
    printmem(memory);
    while(1) {
        int block;
        printf("Enter the length of the block, in multiples of 1k\n");
        scanf("%d", &block);
        memory = fit(memory, block);
        printmem(memory);
    }
    return 0;
}
