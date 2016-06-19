#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
   Tree t;
   t = create();
   inprint(t);
   printf("\n");
   firprint(t);
   printf("\n");
   houprint(t);

    return 0;
}
