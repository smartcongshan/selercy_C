#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

struct Treenode
{
    ElementType data;
    Tree        left;
    Tree        right;
};

Tree create(void)
{
    Tree a = (Tree)malloc(sizeof(Tree));
    Tree b = (Tree)malloc(sizeof(Tree));
    Tree f = (Tree)malloc(sizeof(Tree));
    Tree d = (Tree)malloc(sizeof(Tree));
    Tree c = (Tree)malloc(sizeof(Tree));
    Tree l = (Tree)malloc(sizeof(Tree));
    Tree m = (Tree)malloc(sizeof(Tree));
    Tree n = (Tree)malloc(sizeof(Tree));

    a->data  = 'A';
    a->left  = b;
    a->right = d;

    b->data  = 'B';
    b->left  = NULL;
    b->right = f;

    f->data  = 'F';
    f->left  = f->right = NULL;


    d->data  = 'D';
    d->left  = c;
    d->right = l;

    c->data  = 'C';
    c->left  = c->right = NULL;

    l->data  = 'L';
    l->left  = NULL;
    l->right = m;

    m->data  ='M';
    m->left  = m->right = NULL;

    return a;
}

/* 中序遍历 */
void inprint(Tree p)
{
    if(p != NULL)
    {


        if(p->left != NULL)
        {
            inprint(p->left);
        }

        printf("%c ",p->data);
        if(p->right != NULL)
        {
            inprint(p->right);
        }
    }
}
/* 先序遍历 */
void firprint(Tree p)
{
    if(p != NULL)
    {
         printf("%c ",p->data);
          if(p->left != NULL)
        {
            firprint(p->left);
        }


        if(p->right != NULL)
        {
            firprint(p->right);
        }
    }
}
/* 后序遍历 */
void houprint(Tree p)
{
    if(p != NULL)
    {
          if(p->left != NULL)
        {
            houprint(p->left);
        }


        if(p->right != NULL)
        {
            houprint(p->right);
        }
                 printf("%c ",p->data);

    }
}

