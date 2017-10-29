#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int elem;
    int refbit;
    int modbit;
    struct node *next;
}node;
typedef struct frameptr {
    int set;
    node * ptr;
}frameptr;

int main() {
    int len;
    frameptr hash[10];
    int i,j, inplen;
    int pf;
    int modbit;
    int page;
    node * n, * head, * curr, * temp, * start;
    for (i = 0; i < 10; i++) {
        hash[i].set = 0;
        hash[i].ptr = NULL;
    }
    printf("Enter the frame size\n"); 
    scanf("%d", &len);
    head = (node *) malloc(sizeof(node));
    head->refbit = 0;
    head->modbit = 0;
    n = head;
    for(i = 0; i < len - 1; i++) {
        n->next = (node *) malloc(sizeof(node));
        n = n->next;
        n->refbit = 0;
        n->modbit = 0;
    }
    n->next = head;
    inplen = 0;
    pf = 0;
    curr = head;
    printf("Enter each element of the reference string followed by the value of modified bit\n");
    while(scanf("%d", &page)!=EOF) {
        scanf("%d", &modbit);
        printf("\n"); 
        if(hash[page].set == 0) {
            start = curr;
            while(curr->refbit != 0 && curr->modbit != 0) {
                curr->refbit = 0;
                curr = curr->next;
                if(curr == start)
                    break;
            }
            hash[curr->elem].set = 0;
            hash[curr->elem].ptr = NULL;
            curr->elem = page;
            curr->refbit = 1;
            curr->modbit = modbit;
            hash[page].set = 1;
            hash[page].ptr = curr;
            curr = curr->next; 
            pf++;
        }
        else {
            hash[page].ptr->refbit = 1;
            hash[page].ptr->modbit = modbit;
        }
        temp = head;
        inplen++;
        for(j = 0; j < (pf < len ? pf : len); j++){
            printf("| %d | ref. bit = %d, mod. bit = %d\n", temp->elem, temp->refbit, temp->modbit);
            temp = temp->next;  
        }
        printf("Page faults: %d\n", pf); 
    }
    return 0;
}
