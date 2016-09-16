#ifndef __HASH__H
#define __HASH__H

#define Minsize 5

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;
struct HashEntry;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable hash_init(int );
void destory_table(HashTable );
Position Find(ElementType ,HashTable );
void Insert(ElementType ,HashTable );
void print(Position x);
int hash_h(ElementType key,int size);

#endif
