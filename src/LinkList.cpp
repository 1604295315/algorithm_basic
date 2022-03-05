#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    内存内部，程序内部
    指针变量也是变量
*/

typedef struct LNode{
    int data;
    int *next;
}LNode, LinkList;

LinkList *init(){
    LNode * head;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}