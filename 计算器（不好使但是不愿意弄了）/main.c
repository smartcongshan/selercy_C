#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXSIZE 32

/* ��׺���ʽ�任�ɺ�׺���ʽ
 * s:��Ҫ�����ջ
 * b:��׺���ʽ�Ļ�����
 * a:��׺���ʽ
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
            /* �ŵ������ */
            b[i++] = a[j];
        }
        else
        {


            /* ����Ƿ��ž��жϷ������ȼ� */
            switch(a[j])
            {
                case '(':Push(a[j],s);break;
                case '+':
                case '-':
                    if(Top(s) == '*' || Top(s) == '/')
                    {
                        /* ����������Լ����ȼ��ߵĳ�Ա��Ҫ����ԭ���ķ��Ŷ��������Լ�ѹ�뵽ջ�� */
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
                    pop(s);//ȥ��������
                    break;
                default:break;
            }

            }
        }
        else //aû��������
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
