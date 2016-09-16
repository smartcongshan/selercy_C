#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

struct Stack{

    int  top;
    char str[SIZE];
};

int ismatch(char *p)
{
    struct Stack stack;
    stack.top = -1;
    int i = 0;
    for(i = 0;p[i];i++)
    {
        switch(p[i])
        {
            case '(': ;
            case '[': stack.str[++stack.top] = p[i];break;
            case ')': if(stack.top < 0 || stack.str[stack.top--] != '(')return 0;
                        break;
            case ']': if(stack.top < 0 || stack.str[stack.top--] != '[')return 0;
                        break;
        }

    }
    return stack.top = -1;
}

int main()
{
    int n,i;
    char st[5][10000];
    scanf("%d",&n);
    for(i = 0;i < n;i++)
        scanf("%s",st[i]);
    for(i = 0;i < n;i++)
        if(ismatch(st[i]))
        printf("YES\n");
        else
        printf("NO\n");
    exit(0);
}
