/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is stack
 * simply use push, pop
 * but befor using, please init a base, or it will has error
 * 
 * change the struct to:
typedef struct stackData
{
    unsigned int integer;
}stackData;
 * and run the test code
*/

#include <stdio.h>
#include "stack.h"

int main()
{
    printf("The testing file of stack\n");
    printf("Init a stack\n");
    stackBase* stack = initStackBase();

    printf("push a data\n");
    stackData data;
    data.integer = 100;
    printf("\tpush a integer: %d\n",data.integer);
    push(stack,data);

    printf("push a data\n");
    stackData data1;
    data1.integer = 200;
    printf("\tpush a integer: %d\n",data1.integer);
    push(stack,data1);

    printf("push a data\n");
    stackData data2;
    data2.integer = 300;
    printf("\tpush a integer: %d\n",data2.integer);
    push(stack,data2);

    printf("get stack len: %d\n", getStackLen(stack));

    printf("pop a data\n");
    stackData popdata = pop(stack);
    printf("\tthe data->integer %d\n", popdata.integer);

    printf("pop a data\n");
    stackData popdata1 = pop(stack);
    printf("\tthe data->integer %d\n", popdata1.integer);

    printf("free this stack\n");
    freeStack(stack);

    printf("reach here means the functions work correctly\n");
    return 0;
}