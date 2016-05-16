#include<stdio.h>
#include <stdlib.h>
struct tree{
  int val;
  struct tree *right;
  struct tree *left;
};
struct tree *root=NULL,*r=NULL,*tmp=NULL,*p=NULL;
int add(int n)
{

	tmp=(struct tree*)malloc(sizeof(struct tree));
	if(root ==NULL)
	{
		tmp->val = n;
		tmp->right = NULL;
		tmp->left = NULL;
		root=tmp;
                return;
	}
	else 
	{
		p=root;
		while(p!=NULL)
		{
			r=p;
			if(p->val < n)
			{
				p=p->right;

			}
			else
			{
				p=p->left;
			}
		}
	}

	if(r->val < n)
	{	
        	tmp->val = n;
		tmp->right = NULL;
		tmp->left = NULL;
		r->right =tmp;
	}
	else
	{	
                tmp->val = n;
		tmp->right = NULL;
		tmp->left = NULL;
		r->left = tmp;
	}
	return;
}

void print_inorder(struct tree * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("print in %d\n",tree->val);
        print_inorder(tree->right);
    }
}

void print_postorder(struct tree * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("oost order:%d\n",tree->val);
    }
}
void print_preorder(struct tree * tree)
{
    if (tree)
    {
        printf("%d\n",tree->val);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}
int main()
{
   int k=0;
   while(1)
   {
      printf("Entere the value of element\n");
      scanf("%d",&k);
    
      int n=add(k);
      if(k == 10)
        break;
   }
 
   printf("i am out of main\n");
   printf("Pre Order Display\n");
   print_preorder(root);
   print_postorder(root);
   print_inorder(root);
}

    
          
