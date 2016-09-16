#include "HashSep.h"
#include <stdio.h>
#include <stdlib.h>

struct listnode{
    ElementType element;
    Position next;
};

typedef Position List;

struct hashtab{
    int Tablesize;
    List *TheLists;
};

int hash(ElementType key,int size)
{
    return key % size;
}

int isprime(int x)
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

int NextPrime(int x)
{
    while(!isprime(x))
    {
        x++;
    }
    return x;
}

Hashtable hash_init(int size)
{
    Hashtable h;
    int i;

    if(size < Minsize)
    {
        printf("The size is small!\n");
        return NULL;
    }

    h = malloc(sizeof(struct hashtab));
    if(h == NULL)
    {
        printf("out of space!\n");
        return h;
    }

    h->Tablesize = NextPrime(size);//检验是否为素数，如果不是就变成最近的下一个素数
    printf("%d\n",h->Tablesize);
    h->TheLists = malloc(sizeof(List) * h->Tablesize);
    if(h->TheLists == NULL)
    {
        printf("Out of space!\n");
        return NULL;
    }

    for(i = 0;i < h->Tablesize;i++)
    {
        h->TheLists[i] = malloc(sizeof(struct listnode));
        if(h->TheLists[i] == NULL)
        {
            printf("Out of space\n");
            return NULL;
        }
        else
        {
            h->TheLists[i]->next = NULL;
        }
    }

    return h;
}
void Destoey(Hashtable h)
{

}
Position Find(ElementType x,Hashtable h)
{
    Position p;
    List l;//找到表头

    l = h->TheLists[hash(x,h->Tablesize)];
    p = l->next;

    while(p != NULL && p->element != x)
        p = p->next;
    return p;
}
void Insert(ElementType key,Hashtable h)
{
    Position pos,newcell;
    List l;

    pos = Find(key,h);
    if(pos == NULL)
    {
        newcell = malloc(sizeof(struct listnode));
        if(newcell == NULL)
        {
            printf("Out of space\n");
            return ;
        }
        else
        {
            l = h->TheLists[hash(key,h->Tablesize)];
            newcell->next == l->next;
            newcell->element = key;
            l->next = newcell;
        }
    }
}
void prin(Position p)
{
    printf("%d\n",p->element);
}

