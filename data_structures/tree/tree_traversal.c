#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node *newNode =(struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

//DFS - Inorder
void inorder(struct node* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	printf("%d\n", node->data);
	inorder(node->right);
}

//DFS - Preorder
void preorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%d\n", node->data);
	preorder(node->left);
	preorder(node->right);
}

//DFS - postorder
void postorder(struct node* node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d\n", node->data);
}

//BFS - Using recursion or queues
//Using queues approach
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*10000);
 
    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
	printf("%d ",new_node->data);
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
 


void bfs(struct node *node){
	if (node == NULL)
		return;
	int front, rear;
	struct node **queue = createQueue(&front,&rear);
	enQueue(queue, &rear, node);
	node = deQueue(queue,&front);
	while(node)
	{
		if (node->left){
			enQueue(queue, &rear, node->left);
		}
		if (node->right){
			enQueue(queue, &rear, node->right);
		}
		node = deQueue(queue,&front);
	}
}

//Construct a binary tree
int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->right = newNode(5);
//	inorder(root);
//	preorder(root);
//	postorder(root);
	bfs(root); 

}