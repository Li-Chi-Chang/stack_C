/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is stack
 * simply use push, pop
 * but befor using, please init a base, or it will has error
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int stackerr(int);

// init for this stack
stackBase* initStackBase()
{
    stackBase* base = malloc(sizeof(stackBase));
    if(base == NULL)
        stackerr(STACKALLOCATIONERR);
    base->count = 0;
    base->next = NULL;
    return base;
}

/**
 * return 0: success
 * return 1: error on stack
 * */
int push(stackBase* base, stackData data)
{
    stackNode *newNode = (stackNode*) malloc(sizeof(stackNode));
    if(newNode == NULL)
    {
        return stackerr(STACKALLOCATIONERR);
    }

    if(base->next == NULL)
    {
        base->next = newNode;
    }
    else
    {
        stackNode* pointerNode = base->next;
        while(pointerNode->next != NULL)
        {
            pointerNode = pointerNode->next;
        }
        pointerNode->next = newNode;
    }
    newNode->data = data;
    newNode->next = NULL;
    base->count++;
    return 0;
}

stackData pop(stackBase* base)
{
    stackData data;

    if(base->count > 1)
    {
        stackNode* pointer = base->next;
        int i = base->count;
        for(i = base->count; i > 1; i--)
        {
            pointer = pointer->next;
        }
        data = (pointer->data);
        free(pointer);
    }
    else if(1)
    {
        stackNode* pointer = base->next;
        data = pointer->data;
        free(pointer);
    }
    else
    {
        stackerr(STACKEMPTY);
        return data;
    }
    base->count--;
    return data;
}

int getStackLen(stackBase* base)
{
    return base->count;
}

int freeStack(stackBase* base)
{
    while (base->count != 0)
    {
        pop(base);
    }
    free(base);
    return 0;
}

int stackerr(int errcode)
{
    if(errcode == 0)
    {
        return 0;
    }

    printf("Error here.\nerr code: ");
    switch (errcode)
    {
    case STACKEMPTY:
        printf("%d STACK EMPTY!\n",errcode);
        break;
    case STACKALLOCATIONERR:
        printf("%d STACK ALLOCATION ERR!\n",errcode);
        break;
    default:
        printf("unknown %d\n",errcode);
    }
    exit(1);
}