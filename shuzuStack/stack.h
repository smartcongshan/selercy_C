#ifndef __STACK_H
#define __STACK_H

struct StackRecord;
typedef int ElementType;
typedef struct StackRecord *Stack;

int isempty(Stack);             /* ����Ƿ��ǿ�ջ */
int isfull(Stack);              /* ����Ƿ�����ջ */
Stack create_stack(int);        /* ����һ��ջ����Ҫ�������ֵ */
void destory_st(Stack);         /* ɾ��һ��ջ */
void makempty(Stack);           /* ʹջ�� */
void Push(ElementType ,Stack ); /* ��ջ�������һ��Ԫ�� */
ElementType Top(Stack);         /* ����ջ��Ԫ�� */
void pop(Stack);                /* ɾ��ջ��Ԫ�� */
ElementType TopAndPop(Stack);   /* �鿴��ɾ��ջ��Ԫ�� */

#endif

