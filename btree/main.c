#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct score
{
	int chinese;
	char name[NAMESIZE];
	int id;
};

struct tree
{
	struct score data;
	struct tree *l,*r;
};

struct score *find(struct tree *root,int id)
{
	if(root == NULL)
		return NULL;
	if(id == root->data.id)
		return &root->data;

	if(id < root->data.id)
		return find(root->r,id);
	else
		return find(root->l,id);
}

int insert(struct tree **root,struct score *node)
{
	struct tree *tmp;
	if(*root == NULL)
	{
		tmp = malloc(sizeof(struct tree));
		if(tmp == NULL)
			return -1;
		tmp->l = NULL;
		tmp->r = NULL;
		tmp->data = *node;

		*root = tmp;
		return 0;
	}
	if((*root)->data.id <= node->id)
		return insert(&(*root)->l,node);
	return insert(&(*root)->r,node);
}

void print_s(struct score *data)
{
	printf("%d %s %d\n",data->id,data->name,data->chinese);
}

void _draw(struct tree *root,int level)
{
	int i;
	if(root == NULL) 
		return ;
	_draw(root->r,level + 1);
	for(i = 0;i < level;i++)
		printf("    ");
	printf("%d",root->data.id);
	_draw(root->l,level + 1);
	printf("\n");
}

void draw(struct tree *root)
{
	_draw(root,0);
}

int main()
{
	int arr[] = {4,5,7,6,3,2,1};
	struct tree *tr = NULL;
	struct score tmp,*dataret;
	int i;
	
	for(i = 0;i < sizeof(arr)/sizeof(*arr);i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);
		tmp.chinese = rand()%100;
		insert(&tr,&tmp);
	}
	draw(tr);
#if 0
	i = 2;
	dataret = find(tr,i);
	if(dataret == NULL)
		printf("Can not find id %d\n",i);
	else
		print_s(dataret);
#endif
	exit(0);
}

