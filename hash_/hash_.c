#include "hash_.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum KindOfEntry {Legitimate, Empty, Delete};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int sizetable;
    Cell *TheCells;
};
int hash_h(ElementType key,int size)
{
    return (key % size);

}
static int isprime(int x)
{
    int i;
    int y;
    for(i = 2;i < x;i++)
        if(x%i == 0)
        y = 0;
        if(i>=x)
        y = 1;
    return y;
}

static int NextPrime(int x)
{
    while(!isprime(x))
    {
        x++;
    }
    return x;
}
HashTable hash_init(int size)
{
    HashTable h;
    int i;

    if(size < Minsize)
    {
        printf("The size is too small\n");
        return NULL;
    }

    h = malloc(sizeof(struct HashTbl));
    if(h == NULL)
    {
        printf("Out of space!!!\n");
        return NULL;
    }

    h->sizetable = NextPrime(size);

    h->TheCells  = malloc(sizeof( Cell ) * h->sizetable);
    if(h->TheCells == NULL)
    {
        printf("Out of space\n");
        return NULL;
    }

    for(i = 0;i < h->sizetable;i++)
        h->TheCells[i].Info = Empty;
    return h;

}
void destory_table(HashTable h)
{

}

Position Find(ElementType x,HashTable h)
{
    Position CurrentPos;

    int CollisionNum;

    CollisionNum = 0;

    CurrentPos = hash_h(x,h->sizetable);

    while(h->TheCells[CurrentPos].Info != Empty && h->TheCells[CurrentPos].Element != x)
    {
        CurrentPos += 2 * ++CollisionNum - 1;
        if(CurrentPos >= h->sizetable)
            CurrentPos -= h->sizetable;

    }
    return CurrentPos;
}
void Insert(ElementType x,HashTable h)
{
    Position pos;
    pos = Find( x,h );
    printf("fin ok\n");
    if(h->TheCells[pos].Info != Legitimate)
    {
        h->TheCells[pos].Info = Legitimate;
        h->TheCells[pos].Element = x;
    }
}
void print(Position x)
{
    printf("%d\n",x);
}

