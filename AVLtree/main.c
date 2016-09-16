#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"

int main()
{
    int i;
    int a[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    avltree t = NULL;
    avltree p = NULL;
   // MakeEmpty(tree);


        t = Insert(3,t);
        t = Insert(2,t);
        t = Insert(1,t);
        t = Insert(4,t);
        t = Insert(5,t);
    //for(i = 4;i < 7;i++)
   // t = Insert(i,t);

    pri(t);

    printf("Hello world!\n");
    return 0;
}
