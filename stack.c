#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define ERR_ALLOCATION -1001
#define STACK_OVERFLOW -1002
#define STACK_EMPTY -1003

stack* CreateStack(int dim)
{
    stack *new_stack;

    //allocazione struttura
    new_stack = (stack *)malloc(sizeof(stack));
    if(new_stack == NULL)
        exit(ERR_ALLOCATION);

    //allocazione vettore
    new_stack->stk = (int *)malloc(dim * sizeof(int));
    if(new_stack == NULL)
        exit(ERR_ALLOCATION);

    //inizializzo i valori della struct
    new_stack -> size = dim;
    //punto alla indirizzo di memoria successivo all'ultimo dello stack
    new_stack -> sp = new_stack->stk+dim+1;

    return new_stack;
}

void DeleteStack(stack* s)
{
    free(s->stk);
    free(s);

}

int isFull(stack* s)
{
    //se lo sp punta all ultimo elemento del vettore ...
    return (s->sp == s->stk+(s->size));
}

int isEmpty(stack* s)
{
    //se lo sp punta al primo elemento del vettore ...
    return (s->sp == s->stk);

}

void push(stack* s, int value)
{
    if(!isFull(s))
    {
        *(s -> sp) = value;
        s -> sp++;
    }
    else
        exit(STACK_OVERFLOW);


}

int pop(stack* s)
{
    if(!isEmpty(s))
    {
        s->sp--;
        return *(s->sp);
    }
    else
        exit(STACK_EMPTY);
}

int top(stack* s)
{
    return *(s->sp-1);
}
