#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTos    -1
#define MinSize     5

struct StackRecord{
    int capacity;           //���ջ�����ֵ
    int top;                //ջ��ָ��
    ElementType *array;     //����
};
/* ����Ƿ��ǿ�ջ */
int isempty(Stack S)
{
    return S->top == EmptyTos;
}
/* ����Ƿ�����ջ */
int isfull(Stack S)
{
    return (S->top + 1) == S->capacity;
}
/* ����һ��ջ����Ҫ�������ֵ */
Stack create_stack(int maxsize)
{
    Stack S;
    if(maxsize < MinSize)
    {
        printf("Stack size is too small\n");
        return NULL;
    }
    S = malloc(sizeof(struct StackRecord));
    if(S == NULL)
    {
        printf("Out of space\n");
        return NULL;
    }
    S->array = malloc(sizeof(ElementType) * maxsize);
    if(S->array == NULL)
    {
        printf("Out of space\n");
        return NULL;
    }
    S->capacity = maxsize;
    makempty(S);
    return S;
}
/* ɾ��һ��ջ */
void destory_st(Stack S)
{
    if(S != NULL)
    {
    free(S->array);
    free(S);
    }
}
/* ʹջ�� */
void makempty(Stack S)
{
    S->top = EmptyTos;
}
/* ��ջ�������һ��Ԫ�� */
void Push(ElementType x,Stack S)
{
    if(isfull(S))
    {
        printf("Full Stack\n");
        return ;
    }
    else
        S->array[++S->top] = x;
}
/* ����ջ��Ԫ�� */
ElementType Top(Stack S)
{
    if(!isempty(S))
        return S->array[S->top];
    printf("Empty Stack\n");
    return 0;
}
/* ɾ��ջ��Ԫ�� */
void pop(Stack S)
{
    if(!isempty(S))
    {
        printf("Empty Stack\n");
        return ;
    }
    else
        S->top--;
}
/* �鿴��ɾ��ջ��Ԫ�� */
ElementType TopAndPop(Stack S)
{
    if(!isempty(S))
    {
        return S->array[S->top--];
    }
    else
    {
        printf("Empty Stack\n");
        return NULL;
    }
}


