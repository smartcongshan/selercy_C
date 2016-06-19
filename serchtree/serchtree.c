#include "serchtree.h"
#include <stdio.h>
#include <stdlib.h>

/* 使树变为空树，也可以用来创建树 */
SerchTree MakeEmpty(SerchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}
/* 查找树中元素 */
Position Find(ElementType x,SerchTree T)
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
/* 查找树中最小值 */
Position FindMin(SerchTree T)
{
    if(T == NULL)
        return NULL;
    else
    if(T->left == NULL) //找到最小值了
        return T;
    else                //没找到就继续找
        return FindMin(T->left);
}
/* 查找树中最大值 */
Position FindMax(SerchTree T)
{
    if(T != NULL)
        while(T->right != NULL)
            T = T->right;
    return T;
}
/* 插入一个数值 */
SerchTree Insert(ElementType x,SerchTree T)
{
    if(T == NULL) //如果是个空树
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
        {
            printf("out of space\n");
            return NULL;
        }
        else
        {
            T->Element = x;
            T->left = T->right = NULL;
        }
    }
    else
    if(x < T->Element)
        T->left = Insert(x,T->left);
    else
    if(x > T->Element)
        T->right = Insert(x,T->right);

    return T;
}
/* 查找最小的数 */
Position FndMin(SerchTree T)
{
    if(T == NULL)
    {
        printf("This is a empty tree!\n");
        return NULL;
    }
    else
    if(T->left)
        T->left = FndMin(T->left);
    else
    if(T->left == NULL)
        return T;
    else{}
}
/* 删除一个数 */
SerchTree Delete(ElementType x,SerchTree T)
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
        TmpCell = FndMin(T->right);
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

