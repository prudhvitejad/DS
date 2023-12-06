#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

// Calculate height	
int height(struct Node *N) 
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b) 
{
	return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) 
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) 
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

// Left Rotate
struct Node *leftRotate(struct Node *x) 
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

// Get the balance factor
int getBalanceFactor(struct Node *N) 
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) 
{
	// Find the correct position to insert the node and insert it
	if (node == NULL)
		return (newNode(key));
	if (key < node->key)
		node->left = insertNode(node->left, key);
	else if (key > node->key)
		node->right = insertNode(node->right, key);
	else
		return node;
	
	// Update the balance factor of each node and Balance the tree
	node->height = 1 + max(height(node->left),height(node->right));
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) 
	{
		if (key < node->left->key) 
		{
			return rightRotate(node);
		} 
		else if (key > node->left->key) 
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) 
	{
		if (key > node->right->key) 
		{
			return leftRotate(node);
		} 
		else if (key < node->right->key) 
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

struct Node *minValueNode(struct Node *node) 
{
	struct Node *temp = node;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

// Delete a node
struct Node *deleteNode(struct Node *root, int key) 
{
	// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else 
	{
		if ((root->left == NULL) || (root->right == NULL)) 
		{
			struct Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) 
			{
				temp = root;
				root = NULL;
			} 
			else
				*root = *temp;

			free(temp);
		} 
		else 
		{
			struct Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
		return root;
	
	// Update the balance factor of each node and balance the tree
	root->height = 1 + max(height(root->left),height(root->right));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) 
	{
		if (getBalanceFactor(root->left) >= 0) 
		{
			return rightRotate(root);
		} 
		else 
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) 
	{
		if (getBalanceFactor(root->right) <= 0) 
		{
			return leftRotate(root);
		} 
		else 
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

// Print the tree
void printPreOrder(struct Node *root) 
{
	if (root != NULL) 
	{
		printf("%d ", root->key);
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

int main() 
{
	struct Node *root = NULL;
	root = insertNode(root, 21);	
	root = insertNode(root, 26);	
	root = insertNode(root, 30);	
	root = insertNode(root, 9);
	root = insertNode(root, 4);
	root = insertNode(root, 14);
	root = insertNode(root, 28);
	root = insertNode(root, 18);
	root = insertNode(root, 15);
	root = insertNode(root, 10);
	root = insertNode(root, 2);
	root = insertNode(root, 3);
	root = insertNode(root, 7);
	printPreOrder(root);
	root = deleteNode(root, 18);
	printf("\nAfter deletion: ");
	printPreOrder(root);
}





