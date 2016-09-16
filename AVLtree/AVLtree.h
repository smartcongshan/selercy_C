#ifndef __AVLTREE_H
#define __AVLTREE_H

struct avlnode;
typedef struct avlnode *Position;
typedef struct avlnode *avltree;
typedef int ElementType;

avltree MakeEmpty(avltree );
Position Find(ElementType ,avltree );
Position FindMin(avltree );
Position FindMax(avltree );
avltree Insert(ElementType ,avltree );
avltree Delete(ElementType ,avltree );
void pri(avltree );

#endif
