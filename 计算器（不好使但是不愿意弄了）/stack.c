#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTos    -1
#define MinSize     5

struct StackRecord{
    int capacity;           //这个栈的最大值
    int top;                //栈顶指针
    ElementType *array;     //数组
};
/* 检查是否是空栈 */
int isempty(Stack S)
{
    return S->top == EmptyTos;
}
/* 检查是否是满栈 */
int isfull(Stack S)
{
    return (S->top + 1) == S->capacity;
}
/* 创建一个栈，需要输入最大值 */
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
/* 删除一个栈 */
void destory_st(Stack S)
{
    if(S != NULL)
    {
    free(S->array);
    free(S);
    }
}
/* 使栈空 */
void makempty(Stack S)
{
    S->top = EmptyTos;
}
/* 往栈里面插入一个元素 */
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
/* 产看栈顶元素 */
ElementType Top(Stack S)
{
    if(!isempty(S))
        return S->array[S->top];
    printf("Empty Stack\n");
    return 0;
}
/* 删除栈顶元素 */
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
/* 查看并删除栈顶元素 */
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


