#ifndef __SERCHTREE_H
#define __SERCHTREE_H

typedef int ElementType;
typedef struct TreeNode *SerchTree; //������ߴ�����ʱ����
typedef struct TreeNode *Position;  //����λ�õ�ʱ����
struct TreeNode{
    int Element; //���е�ֵ
    SerchTree   left;    //������
    SerchTree   right;   //������
};


SerchTree MakeEmpty(SerchTree );          //ʹ����Ϊ������Ҳ��������������
Position Find(ElementType ,SerchTree );   //��������Ԫ��
Position FindMin(SerchTree );             //����������Сֵ
Position FindMax(SerchTree );             //�����������ֵ
SerchTree Insert(ElementType ,SerchTree );//����һ����ֵ
SerchTree Delete(ElementType ,SerchTree );//ɾ��һ����ֵ

#endif
