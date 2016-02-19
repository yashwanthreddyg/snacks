#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node node;

int howManyOf(node *n, int n1, int n2, int *ancestor)
{
	if (n == NULL)
	{
		return 0;
	}
	if (n->data == n1 || n->data == n2)
	{
		return 1;
	}
	int leftCount = howManyOf(n->left, n1, n2, ancestor);
	int rightCount = howManyOf(n->right, n1, n2, ancestor);
	if (leftCount == 1 && rightCount == 1)
	{
		*ancestor = n->data;
		return 2;
	}
	else
		return leftCount + rightCount;
}

int main()
{
	node* root = (node*)malloc(sizeof(node));
	node* l1 = (node*)malloc(sizeof(node));
	node* l2 = (node*)malloc(sizeof(node));
	node* l3 = (node*)malloc(sizeof(node));
	node* l4 = (node*)malloc(sizeof(node));
	node* l5 = (node*)malloc(sizeof(node));
	node* l6 = (node*)malloc(sizeof(node));
	node* l7 = (node*)malloc(sizeof(node));

	root->left = l1;
	root->right = NULL;
	root->data = 0;

	l1->left = l2;
	l1->right = l3;
	l1->data = 1;

	l2->left = NULL;
	l2->right = NULL;
	l2->data = 2;

	l3->left = l4;
	l3->right = l5;
	l3->data = 3;

	l4->left = NULL;
	l4->right = NULL;
	l4->data = 4;

	l5->left = l6;
	l5->right = l7;
	l5->data = 5;

	l6->left = NULL;
	l6->right = NULL;
	l6->data = 6;

	l7->left = NULL;
	l7->right = NULL;
	l7->data = 7;

	int ancestor = -1;
	howManyOf(root, 2, 4, &ancestor);

	printf("%d\n", ancestor);
	scanf("%d");
}
