#ifndef __SEQUENLIST_H
#define __SEQUENLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
    int *data;
    int length, size;
} Vector;

Vector * init(int n);
int expend(Vector * vec);
int insert(Vector *vec, int ind, int val);
int erase(Vector *vec, int ind);
void output(Vector * vec);
void clear(Vector *vec);

#endif