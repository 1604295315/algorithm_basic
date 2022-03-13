#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinkNode {
    int data;
    LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head; //虚拟头节点
    int length;
} LinkList;

LinkNode *init_linknode(int val) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;

    LinkNode *p = &l->head;
    LinkNode *node = init_linknode(val);
    while(ind --) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(LinkList *l, int ind) {
    
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;

    LinkNode *p = &l->head, *node;
    while (ind --) {
        p = p->next;
    }
    node = p->next->next;
    free(p->next);
    p->next = node;
    l->length -= 1;
    return 1;
}

void clear_linknode(LinkNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_linklist(LinkList *l) {
    if (l == NULL) return ;

    LinkNode *p = &l->head, *q;
    while(p) {
        q = p->next;
        clear_linknode(p);
        p = q;
    }
    free(l);
    return ;
}

void output(LinkList *l) {
    printf("LinkList(%d) :", l->length);
    for (LinkNode *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
    return ;
}

#define MAX_OP 20

int main() {
    srand(time(0));

    LinkList *l = init_linklist();
    
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3;
        int ind = rand() % (l->length + 1);
        int val = rand() % 100;
        
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to LinkList = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase item at %d from LinkList = %d\n", ind, erase(l, ind));
            } break;
            default:
            break;
        }
        output(l);
        printf("\n");
    }
    clear_linklist(l);
    return 0;
}