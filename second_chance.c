#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
    int elem;
    int refbit;
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
    int arr[128];
    node * n, * head, * curr, * temp;
    for (i = 0; i < 10; i++) {
        hash[i].set = 0;
        hash[i].ptr = NULL;
    }
    printf("Enter the frame size\n"); 
    scanf("%d", &len);
    head = (node *) malloc(sizeof(node));
    head->refbit = 0;
    n = head;
    for(i = 0; i < len - 1; i++) {
        n->next = (node *) malloc(sizeof(node));
        n = n->next;
        n->refbit = 0;
    }
    n->next = head;
    printf("Enter the reference string\n");
    inplen = 0;
    while(scanf("%d", &arr[inplen])!=EOF) {
        inplen++;
    }
    pf = 0;
    curr = head;
    for(i = 0; i < inplen; i++) {
            printf("\n"); 
        if(hash[arr[i]].set == 0) {
            while(curr->refbit != 0) {
                curr->refbit = 0;
                curr = curr->next;
            }
            hash[curr->elem].set = 0;
            hash[curr->elem].ptr = NULL;
            curr->elem = arr[i];
            hash[arr[i]].set = 1;
            hash[arr[i]].ptr = curr;
            curr = curr->next; 
            pf++;
        }
        else {
            hash[arr[i]].ptr->refbit = 1;
        }
        temp = head;
        for(j = 0; j < (pf < len ? pf : len); j++){
            printf("| %d | ref. bit = %d\n", temp->elem, temp->refbit);
            temp = temp->next;  
        }
            printf("Page faults: %d\n", pf); 
    }
    return 0;
}
