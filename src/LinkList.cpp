#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    内存内部，程序内部
    指针变量也是变量
*/
//结构定义
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode;

typedef struct LinkList {
    LNode * head;
    int length;
} LinkList;

//结构操作
LNode *init_listnode(int val){
    //带头节点的尾插法
    LNode * p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head = NULL;
    l->length = 0;
    return l;
}

void clear_linknode(LNode *node){
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_linklist(LinkList *l){
    if (l == NULL) return ;
    LNode *p = l->head, *q;
    while (p) {
        q = p->next;
        clear_linknode(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(LinkList *l, int ind, int val){
    if (l == NULL) return 0;
    if (ind <0 || ind >= l->length) return 0;
    // 虚拟头节点
    LNode *p = l->head;
}

int main() {
    
    return 0;
}