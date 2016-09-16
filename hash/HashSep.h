#ifndef __HashSep_H
#define __HashSep_H

#define Minsize 5


struct listnode;
struct hashtab;
typedef struct hashtab  *Hashtable;
typedef struct listnode *Position;
typedef unsigned int ElementType;

Hashtable hash_init(int );
void Destoey(Hashtable );
Position Find(ElementType ,Hashtable );
void Insert(ElementType ,Hashtable );
void prin(Position );

#endif

