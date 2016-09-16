#ifndef __STACK_H
#define __STACK_H

struct StackRecord;
typedef int ElementType;
typedef struct StackRecord *Stack;

int isempty(Stack);             /* 检查是否是空栈 */
int isfull(Stack);              /* 检查是否是满栈 */
Stack create_stack(int);        /* 创建一个栈，需要输入最大值 */
void destory_st(Stack);         /* 删除一个栈 */
void makempty(Stack);           /* 使栈空 */
void Push(ElementType ,Stack ); /* 往栈里面插入一个元素 */
ElementType Top(Stack);         /* 产看栈顶元素 */
void pop(Stack);                /* 删除栈顶元素 */
ElementType TopAndPop(Stack);   /* 查看并删除栈顶元素 */

#endif

