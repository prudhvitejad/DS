#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define alpha_size 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct TrieNode
{
	struct TrieNode *children[alpha_size];
	int isLeaf;
};

struct TrieNode* createNode()
{
	struct TrieNode* pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	for ( int i = 0; i < alpha_size; i++)
		pNode->children[i] = NULL;
	pNode->isLeaf = false ;
	return pNode;
};

struct TrieNode* insert_node( struct TrieNode* root, char * key)
{
	int level;
	int length = strlen (key);
	struct TrieNode* pCrawl = root;
	for (level = 0; level < length; level++)
	{
		int index = key[level] - 'a' ;
		if (pCrawl->children[index] == NULL)
			pCrawl->children[index] = createNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isLeaf = true ;
	return root;
}

bool isLeafNode( struct TrieNode* root)
{
	return root->isLeaf != false ;
}

void display( struct TrieNode* root, char str[], int level)
{
	if (isLeafNode(root))
	{
		str[level] = '\0' ;
		printf("%s\n",str);
	}
	int i;
	for (i = 0; i < alpha_size; i++)
	{
		if (root->children[i])
		{
			str[level] = i + 'a' ;
			display(root->children[i], str, level + 1);
		}
	}
}

bool isEmpty(struct TrieNode* root)
{
	for ( int i = 0; i < alpha_size; i++)
		if (root->children[i])
			return false ;
		return true ;
}

struct TrieNode*  delete(struct TrieNode* root, char key[], int depth)
{
	if (!root)
		return NULL;
	if (depth == strlen(key)) 
	{
		if (root->isLeaf)
		root->isLeaf = false ;
		if (isEmpty(root)) 
		{
			free (root);
			root = NULL;
		}
		return root;
	}
	int index = key[depth] - 'a' ;
	root->children[index] =
	delete (root->children[index], key, depth + 1);
	if (isEmpty(root) && root->isLeaf == false ) 
	{
		free (root);
		root = NULL;
	}
	return root;
}

bool search( struct TrieNode* root, char key[])
{
	struct TrieNode* pCrawl = root;
	for ( int i = 0; i < strlen(key); i++) 
	{
		int index = key[i] - 'a' ;
		if (!pCrawl->children[index])
			return false ;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isLeaf);
}

int main()
{
	char keys[][8] = { "the" , "a" , "there" , "answer" ,"any" , "by" , "bye" , "their" };
	struct TrieNode* root = (struct TrieNode*)malloc(sizeof(struct TrieNode));	// root = createNode();
	for(int i=0;i<alpha_size;i++)
		root->children[i] = NULL;
	for ( int j = 0; j < ARRAY_SIZE(keys); j++)
	root = insert_node(root, keys[j]);
	int level = 0;
	char str[20];
	printf("Content of Trie: \n");
	display(root, str, level);
	
	int depth = 0;
	root = delete(root,"hero",depth);
	
	printf("After Deletion Content of Trie: \n");
	display(root, str, level);
	
	printf("\nSearching:");
	search(root, "the" ) ?  printf("\nYes") : printf("\nNo") ;
	search(root, "these" ) ? printf("\nYes") : printf("\nNo") ;
}





