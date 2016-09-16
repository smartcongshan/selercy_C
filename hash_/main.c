#include <stdio.h>
#include <stdlib.h>
#include "hash_.h"

int main()
{
    int i;
    HashTable h;
    Position x;
    h = hash_init(11);
    printf("init ok\n");
    for(i = 0;i < 5;i++)
        Insert(i,h);
    printf("insert ok\n");
    x = Find(0,h);
    printf("find ok\n");
    print(x);
    return 0;
}
