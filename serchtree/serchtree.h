#ifndef __SERCHTREE_H
#define __SERCHTREE_H

typedef int ElementType;
typedef struct TreeNode *SerchTree; //定义或者创建的时候用
typedef struct TreeNode *Position;  //传递位置的时候用
struct TreeNode{
    int Element; //树中的值
    SerchTree   left;    //左子树
    SerchTree   right;   //右子树
};


SerchTree MakeEmpty(SerchTree );          //使树变为空树，也可以用来创建树
Position Find(ElementType ,SerchTree );   //查找树中元素
Position FindMin(SerchTree );             //查找树中最小值
Position FindMax(SerchTree );             //查找树中最大值
SerchTree Insert(ElementType ,SerchTree );//插入一个数值
SerchTree Delete(ElementType ,SerchTree );//删除一个数值

#endif
