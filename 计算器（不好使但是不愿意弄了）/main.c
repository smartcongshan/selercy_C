#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXSIZE 32

/* 中缀表达式变换成后缀表达式
 * s:需要输入的栈
 * b:后缀表达式的缓存区
 * a:中缀表达式
 */
void change(Stack s,int *b,int *a)
{
    int i = 0;
    int j;
    for(j = 0;j < sizeof(a)/sizeof(*a);j++)
    {
        if(a[j] != '\0')
        {
        if(a[j] > '0' && a[j] < '9')
        {
            /* 放到输出中 */
            b[i++] = a[j];
        }
        else
        {


            /* 如果是符号就判断符号优先级 */
            switch(a[j])
            {
                case '(':Push(a[j],s);break;
                case '+':
                case '-':
                    if(Top(s) == '*' || Top(s) == '/')
                    {
                        /* 如果碰到比自己优先级高的成员就要将其原来的符号读出并将自己压入到栈中 */
                        while(Top(s) != '(' || Top(s) != 0)
                        {
                            b[i++] = TopAndPop(s);
                        }
                        Push(a[j],s);
                    }
                    else
                    {
                        Push(a[j],s);
                    }
                    break;
                case '*':
                case '/':
                    Push(a[j],s);break;
                case ')':
                    while(Top(s) != '(')
                    {
                        b[i++] = TopAndPop(s);
                    }
                    pop(s);//去掉左括号
                    break;
                default:break;
            }

            }
        }
        else //a没有数据了
        {
            while(!isempty(s))
            {
                b[i++] = TopAndPop(s);
            }
        }
    }
}

int main()
{
    int f;
    char b[MAXSIZE];
    char a[] = "(10+5)*3+16-1";
    Stack s = NULL;
    s = create_stack(32);
    change(s,b,a);
    for(f = 0;f < sizeof(b)/sizeof(*b);f++)
        printf("%d ",b[f]);
    //ret = compute(b);
   // printf("%d\n",ret);
    return 0;
}
