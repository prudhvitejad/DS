#include <stdio.h>
#include <stdlib.h>
#define max 10

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* Queue[max];
int rear=-1,front=-1;

struct node* Stack[max];
int top=-1;

void push(struct node *root)
{
	if(top == max-1)
	{
		printf("\nStack Overflow");
	}
	top++;
	Stack[top] = root;
}

struct node* pop()
{
	if(top == -1)
	{
		printf("\nStack Underflow");
	}
	return Stack[top--];
}

struct node* peek()
{
	if(top == -1)
	{
		printf("\nStack Underflow");
	}
	return Stack[top];
}

int isEmptyStack()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

void Enqueue(struct node *root)
{
	if(front==(rear+1)%max)
		printf("\n-----Circular Queue overflow------\n");
	else
	{
		if(rear==-1 && front==-1)
		{
			front=rear=0;	
			Queue[front]=root;
			return;
		}
		rear=(rear+1)%max;
					
		Queue[rear]=root;
	}
}

struct node* Dequeue()
{
	int temp;
	if(front==-1&&rear==-1)
	{
		printf("\n-----Queue Underflow------\n");
	}
	else if(front==rear)
	{
		//printf("Deleted element is %d",Queue[front]);
		temp = front;
		front=rear=-1;
		return Queue[temp];
	}
	else
	{
		//printf("Deleted element is %d",Queue[front]);
		temp = front;
		front=(front+1)%max;
		return Queue[temp];
	}
}

int isEmptyQueue()
{
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

/*
    #We use Level Order traversal logic to add/insert the nodes to the binary tree.
        
    if root is Null
    	then new node become root
    else
        create a Queue and enqueue the root node to it.
        iterate until the queue length becomes zero
            temp-node = dequeue()
            if temp-node -> left is Null
                temp-node-> left = new-node
            else
                enqueue the temp-node-> left
            if temp-node -> right is Null
                temp-node-> right = new-node
            else
                enqueue the temp-node-> right
*/

struct node* insert(struct node *root,int data)
{
	struct node *temp;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->left = new->right = NULL;
	
	if(!root)
	{
		root = new;
		return root;
	}
	
	Enqueue(root);
	
	while(!isEmptyQueue())
	{
		temp = Dequeue();
		if(temp->left)
			Enqueue(temp->left);
		else
		{
			temp->left = new;
			while(!isEmptyQueue())
				Dequeue();
				
			return root;
		}
		
		if(temp->right)
			Enqueue(temp->right);
		else
		{
			temp->right = new;
			while(!isEmptyQueue())
				Dequeue();

			return root;
		}
	}
	
}

void preorder(struct node *root)
{
	if(root)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

/*
	Level order traversal is defined as follows:
	• Visit the root.
	• While traversing level (keep all the elements at level + 1 in queue)
	• Go to the next level and visit all the nodes at that level.
 	• Repeat this until all levels are completed.
*/

void levelorder(struct node *root)
{
	struct node *temp;
	if(!root)
		return;
	Enqueue(root);
	while(!isEmptyQueue())
	{
		temp = Dequeue();
		printf("%d->",temp->data);
		if(temp->left)
			Enqueue(temp->left);
		if(temp->right)
			Enqueue(temp->right);
	}
}

/*
	In	the	recursive version, a stack is required as we need to remember the current node so that after completing the left subtree we	
	can go to the right subtree. To simulate the same, first we process the current node and before going to the left subtree, we store
	the current node on stack. After completing	the left subtree processing, pop the element and go to its right subtree. Continue this
 	process	until stack is nonempty.
*/
void preorderIterative(struct node *root)
{
	if (root == NULL)
		return;
	
	push(root);
	while(!isEmptyStack())
	{
		struct node *temp = pop();
		printf("%d->",temp->data);

		if(temp->right != NULL)
			push(temp->right);

		if(temp->left != NULL)
			push(temp->left);
	}
}

/*
	The Non-recursive version of Inorder traversal	is similar to Preorder. The	only change	is, instead of processing the node before
	going to left subtree, process it after	popping	(which is indicated after completion of left subtree processing).
*/
void inorderIterative(struct node *root)
{
    struct node *current = root;

    while (current != NULL || !isEmptyStack())
    {
        // Reach the leftmost node of the current node
        while (current != NULL)
        {
            push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop();
        
        // Process the current node
        printf("%d->", current->data);
        
        // Visit the right subtree
        current = current->right;
    }
}

/*
	In preorder and inorder traversals, after popping the stack element we do not need to visit the same vertex again. But in postorder
	traversal, each node is visited twice. That means, after processing the left subtree we will visit the current node and after processing
	the right subtree we will visit the same current node. But we should be processing the node during the second visit. Here the problem
	is how to differentiate whether we are returning from the left subtree or the right subtree.
*/
/*
	We use a previous variable to keep track of the earlier traversed node.
	
	Let’s assume current is the current node that is on top of the stack. When previous is current’s parent, we are traversing down the tree. In this case, we try to traverse to current’s left child
	if available (i.e., push left child to the stack). If it is not available, we look at current’s right child. If both left and right
	child do not exist (i.e, current is a leaf node), we print current’s value and pop it off the stack.

	If prev is current’s left child, we are traversing up the tree from the left. We look at current’s right child. If it is available,
	then traverse down the right child (i.e., push right child to the stack), otherwise print current’s value and pop it off the stack.
	If previous is current’s right child, we are traversing up the tree from the right. In this case, we print current’s value and pop
	it off the stack.

Algorithm:
----------

1.Initial Setup:
	The function checks if the tree's root is NULL. If it is, the function returns immediately since there is nothing to traverse.
	If the tree is not empty, the root node is pushed onto the stack, and the traversal begins.

2.Main Loop:
	The loop runs until the stack is empty.
	Inside the loop, the current node is set to the top node of the stack (peek()).

3.Traversal Logic:

	3.1 Traversing Down the Tree:
		If prev is NULL or prev is the parent of current (meaning we're moving down the tree), the code checks if the current node has a left child.
		If a left child exists, it is pushed onto the stack.
		If no left child exists, the code checks for a right child.
		If no children exist (i.e., current is a leaf node), it prints the current node's value and pops the node off the stack.

	3.2 Traversing Up from the Left Child:
		If the prev node is the left child of current, it indicates that the left subtree has been fully processed, so the code now checks for a right child.
		If a right child exists, it is pushed onto the stack.
		If no right child exists, the current node's value is printed, and it is popped from the stack.

	3.3 Traversing Up from the Right Child:
		If prev is the right child of current, both subtrees have been processed, so the code prints the current node's value and pops it from the stack.

4.Update Previous Pointer:
	At the end of the loop, the prev pointer is updated to current to keep track of the previously processed node.
*/
void postorderIterative(struct node *root)
{
    if (root == NULL)
        return;

    struct node *prev = NULL;
    struct node *current = root;

    // Push the root node onto the stack
    push(current);

    while (!isEmptyStack())
    {
        current = peek();

        // Traverse down the tree
        if (prev == NULL || prev->left == current || prev->right == current)
        {
            if (current->left)
                push(current->left);
            else if (current->right)
                push(current->right);
            else
            {
                // If current is a leaf node
                printf("%d->", current->data);
                pop();
            }
        }
        
		// Traverse up from the left child
        else if (current->left == prev)
        {
            if (current->right)
                push(current->right);
            else
            {
                printf("%d->", current->data);
                pop();
            }
        }
        
		// Traverse up from the right child
        else if (current->right == prev)
        {
            printf("%d->", current->data);
            pop();
        }

        prev = current;
    }
}

/*
PostOrder traversal using 2 stacks.

Stack1 is used to simulate the recursive postorder traversal. Nodes are pushed into stack1 and then transferred to stack2.
Stack2 reverses the order of nodes from stack1. When stack1 is emptied, stack2 contains nodes in the order required for postorder traversal (left, right, root).
Finally, popping and printing nodes from stack2 results in the correct postorder sequence.

Algorithm:
-------------
1.Initial Setup:
	If the root is NULL, return immediately as there's nothing to traverse.
	Otherwise, push the root onto the first stack (stack1).

2.Main Loop:
	While stack1 is not empty:
		Pop an element from stack1 and push it onto stack2.
		If the popped node has a left child, push it onto stack1.
		If the popped node has a right child, push it onto stack1.

3.Processing Stack 2:
	Once all nodes are in stack2, pop nodes from stack2 one by one and print their values (this gives the postorder traversal).


void postorderIterativeUsing2Stacks(struct node  *root) {
	if (root == NULL)
		return;

	stack1.push(root);

    	// Iterate until stack1 is empty
    	while (!stack1.empty()) 
	{
        	struct node *current = stack1.pop();
        	stack2.push(current);

        	// Push left and right children of the popped node to stack1
        	if (current->left)
            		stack1.push(current->left);

        	if (current->right)
            		stack1.push(current->right);
    }

	// Pop all items from stack2 and print them
    	while (!stack2.empty()) {
        	struct node *node = stack2.top();
        	printf("%d->",node->data);
    }
}
*/

struct node* search(struct node *root,int data)
{
	struct node *temp;
	if(root == NULL)
		return NULL;
	else
	{
		if(root->data == data)
			return root;
		else
		{
			temp = search(root->left,data);
			if(temp != NULL)
				return temp;
			else return search(root->right,data);
		}
	}
	return NULL;
}

struct node* delete_full_tree(struct node *root)
{
	if( root == NULL )
		return NULL;
		
	delete_full_tree(root->left);
	delete_full_tree(root->right);
	
	free(root);
}

struct node* swap(struct node *root)
{
	struct node *temp;
	if(root)
	{
		swap(root->left);
		swap(root->right);
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}


int main()
{
	int ch1,ch2,flag,key,val;
	struct node *root = NULL;
	struct node *new = NULL;
	struct node *temp = NULL;
	
	do
	{
		printf("\nMENU\n***********\n");
		printf("1.Insertion\n2.Display\n3.Search\n4.Deletion(Entire tree deletion)\n5.Exit\n6.QueueEmpty\n7.Swap Left and Right Childs\nEnter your choice:");
		scanf("%d",&ch1);
		
		switch(ch1)
		{
			case 1:
				printf("Enter The value:");
				scanf("%d",&val);
				root = insert(root,val);
				break;
				
			case 2:
				printf("\n1.PreOrder\n2.InOrder\n3.PostOrder\n4.LevelOrder\n5.PreOrderIterative\n6.InorderIteratve\n7.PostOrderIterative\nEnter Your Choice:");
				scanf("%d",&ch2);
				
				switch(ch2)
				{
					case 1:
						preorder(root);
						break;
					
					case 2:
						inorder(root);
						break;
					
					case 3:
						postorder(root);
						break;
					
					case 4:
						levelorder(root);
						break;

					case 5:
						preorderIterative(root);
						break;
					
					case 6:
						inorderIterative(root);
						break;
					
					case 7:
						postorderIterative(root);
						break;
				}
				break;
				
			case 3:
				printf("Enter the key to be searched:");
				scanf("%d",&key);
				temp = search(root,key);
				if( temp == NULL )
					printf("\nThe key is not found\n");
				else
					printf("\nThe key is found\n");
				break;
				
			case 4:
				root = delete_full_tree(root);
				break;
				
			case 5:
				exit(0);
				break;
			
			case 6:
				key = isEmptyQueue();
				if(key==1)
					printf("\nQueue is Empty\n");
				else
					printf("\nQueue is not Empty\n");
				break;
			
			case 7:
				root = swap(root);
				break;
		}
		
		printf("\nDo you want to continue (press 1)");
		scanf("%d",&flag);
	}while(flag == 1);
}





