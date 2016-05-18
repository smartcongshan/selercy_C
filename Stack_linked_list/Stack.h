#ifndef __Stack_h

typedef int ElementType;
struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;

int IsEmpty(Stack);
Stack CreateStack(void);
void DestoryStack(Stack);
void MakeEmpty(Stack);
void Push(ElementType ,Stack );
ElementType Top(Stack);
void Pop(Stack);

#endif // __STACK_H

