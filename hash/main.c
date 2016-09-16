#include <stdio.h>
#include <stdlib.h>
#include "HashSep.h"

int main()
{
    Position p = NULL;
    int i,a;
    Hashtable h;
    h = hash_init(11);

    for(i = 0;i < 5;i++)
    {
    Insert(i,h);
      //  printf("%d\n",i);
    }
    p = Find(2,h);

    prin(p);
}
