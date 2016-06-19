#ifndef __TREE_H
#define __TREE_H

struct Treenode;

typedef char ElementType;
typedef struct Treenode *Tree;

Tree create(void);
void inprint(Tree p);
void firprint(Tree p);
void houprint(Tree p);

#endif

