#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//il programma è funzionante ma non restituisce gli errori : stack overflow e stack empty

int main()
{

    int tmp,x;
    stack *s = CreateStack(5);


    do{
    printf("menu:\n1-pop\n2-push\n3-top\n>");
    scanf("%d",&tmp);

    if(tmp == 1)
        printf("%d\n",pop(s));
    else if(tmp == 2)
    {
        printf("what number?\n>");
        scanf("%d",&tmp);
        push(s,tmp);
    }
    else if(tmp == 3)
        printf("%d",top(s));
    else
        printf("error wrong numb\n");

    printf("1 to continue 0 to exit\n>");
    scanf("%d",&x);

    }while(x == 1);

    return 0;
}
