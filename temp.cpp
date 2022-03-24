#include <stdio.h> 
#include <stdlib.h> 
typedef struct node {
    int data;
    struct node *next; 
} node; 

typedef struct stack {
    struct node *head; 
    int size; 
} stack; 
    
node *get_new_node(int x) {
    node *p = (node *)malloc(sizeof(node)); 
    p->data = x; 
    p->next = NULL; 
    return p; 
}

stack *init_stack() { 
    stack *s = (stack *)malloc(sizeof(stack)); 
    s->head = get_new_node(-1); 
    s->size = 0; 
    return s; 
} 

void delete_stack(stack *s) { 
    node *p = s->head; 
    while (p != NULL) { 
        node *q = p->next; 
        free(p);
        p = q;
    }
}