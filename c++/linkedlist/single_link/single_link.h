#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

#include <stdlib.h>
#include <iostream>

typedef struct listNode {
    struct listNode *next;
    void *value;
}listNode;

typedef struct linkedList {
    listNode *head;
    size_t len;
    size_t typesize;

    void(*dup)(void*, void*);
    void(*match)(void*, void*);
    void(*free)(void*);
}linkedList;

linkedList *listCreate();



#endif // __SINGLELIST_H__
