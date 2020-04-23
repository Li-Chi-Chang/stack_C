/**
 * COPYRIGHT
 * AUTHOR: Li-Chi, Chang
 * 
 * descreption:
 * This is stack
 * simply use push, pop
 * but befor using, please init a base, or it will has error
*/

typedef struct stackData
{
    unsigned int integer;
}stackData;

// struct for the stack
typedef struct stackNode
{
    stackData data;
    struct stackNode *next;
}stackNode;

typedef struct
{
    unsigned int count;
    struct stackNode *next;
}stackBase;

/**
 * descreption: init this stack
 * input:
 * output: a stack base
 */
stackBase* initStackBase();

/**
 * descreption: push data into the stack
 * input: the stack base, data in unsigned int format
 * output: 0:success, 1 err
 */
int push(stackBase*, stackData);

/**
 * descreption: pop the top layer of this stack
 * input: the stack base
 * output: data in unsigned int
 */
stackData pop(stackBase*);

/**
 * descreption: get the length of this stack
 * input: the stack base
 * output: the length of this stack
 */
int getStackLen(stackBase*);

/**
 * descreption: free all the space
 * input: the stack base
 * output: 0 success
 */
int freeStack(stackBase*);

/**
 * descreption: error code
 */
#define STACKEMPTY 0xFFFFFFFF
#define STACKALLOCATIONERR 0x04