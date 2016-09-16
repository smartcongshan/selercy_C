#include "AVLtree.h"
#include <stdio.h>
#include <stdlib.h>

struct avlnode{
    ElementType Element;
    avltree     left;
    avltree     right;
    int         height;
};


static int height(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->height;
}

avltree MakeEmpty(avltree T)
{
    if(T != NULL)
    {
        T->left   = NULL;
        T->right  = NULL;
        T->height = 0;
    }
}
Position Find(ElementType x,avltree T)
{
    if(T == NULL)
        return NULL;
    if(x < T->Element)
        Find(x,T->left);
    else
    if(x > T->Element)
        Find(x,T->right);
    else
        return T;
}
Position FindMin(avltree T)
{
     if(T == NULL)
        return NULL;
    else
    if(T->left == NULL) //找到最小值了
        return T;
    else                //没找到就继续找
        return FindMin(T->left);
}
Position FindMax(avltree T)
{
     if(T != NULL)
        while(T->right != NULL)
            T = T->right;
    return T;
}

static Max(int a,int b)
{
    return a > b ? a : b;
}
/* 单旋转 */
static Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    if(k2->left != NULL)
    {
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    }
    else
    {
 k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    }
    k2->height = Max(height(k2->left),height(k2->right)) + 1;
    k1->height = Max(height(k1->left),k2->height) + 1;

    return k1;
}
/* 双旋转 */
static Position DoubleRotateWithLeft(Position k3)
{
    k3->left = SingleRotateWithLeft(k3->left);

    return SingleRotateWithLeft(k3);
}
/* 插入 */
avltree Insert(ElementType x,avltree T)
{
    if(T == NULL)
    {
        printf("1 %d\n",x);
        T = malloc(sizeof(struct avlnode));
        if(T == NULL)
        {
            printf("out of space\n");
            return NULL;
        }
        else
        {
            T->Element = x;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }
    else if(x < T->Element)
    {

        T->left = Insert(x,T->left);
        if(height(T->left) - height(T->right) == 2)
        {
            if(x < T->left->Element)
            {
                printf("S %d\n",x);
                T = SingleRotateWithLeft( T );
            }
            else
            {
                printf("D %d\n",x);
                T = DoubleRotateWithLeft( T );
            }
        }
    }
    else if(x > T->Element)
    {
         printf("3 %d\n",x);
         T->right = Insert(x,T->right);
        if(height(T->right) - height(T->left) == 2)
        {
            if(x > T->right->Element)
            {printf("S %d\n",x);
            printf("%d",T->Element);
                T = SingleRotateWithLeft( T );
            }
            else
            {printf("D %d\n",x);
                T = DoubleRotateWithLeft( T );
            }
        }
    }
    T->height = Max(height(T->right),height(T->left)) + 1;
    return T;
}
/* 删除一个元素 */
avltree Delete(ElementType x,avltree T)
{
      Position TmpCell;
    if(T == NULL)
    {
        printf("Element not found!\n");
        return NULL;
    }
    else
    if(x < T->Element)
        T->left  = Delete(x,T->left);
    else
    if(x > T->Element)
        T->right = Delete(x,T->right);
    else
    if(T->left && T->right)//x = T->Element
    {
        TmpCell = FindMin(T->right);
        T->Element = TmpCell->Element;
        T->right = Delete(T->Element,T->right);
    }
    else
    {
        TmpCell = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
        free(TmpCell);
    }
    return T;
}
void pri(avltree T)
{

  //  if(T->left != NULL)
  //  print(T->left);


   // if(T->right != NULL)
   // print(T->right);

     printf("%d\n",T->Element);

}

