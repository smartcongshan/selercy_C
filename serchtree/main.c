#include <stdio.h>
#include <stdlib.h>
#include "serchtree.h"

int main()
{
    ElementType x;
    SerchTree T = NULL;
    T = MakeEmpty(T);
    x = 1;
    T = Insert(x,T);
    x = 5;
    T = Insert(x,T);
    printf("%d\n",T->Element);
    printf("%d\n",T->right->Element);
    Delete(x,T);
    T = Insert(2,T);
    printf("%d\n",T->Element);
    printf("%d\n",T->right->Element);
    return 0;
}
