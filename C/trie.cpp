#include <iostream>
#include <string.h>
#define alpha_size 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
using namespace std;

struct TrieNode
{
	struct TrieNode* children[alpha_size];
	bool isLeaf;
};

struct TrieNode* createNode()
{
	struct TrieNode* pNode = new TrieNode;
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
		cout << str << endl;
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

bool isEmpty(TrieNode* root)
{
	for ( int i = 0; i < alpha_size; i++)
		if (root->children[i])
			return false ;
		return true ;
}

TrieNode* remove (TrieNode* root, string key, int depth = 0)
{
	if (!root)
		return NULL;
	if (depth == key.size()) 
	{
		if (root->isLeaf)
		root->isLeaf = false ;
		if (isEmpty(root)) 
		{
			delete (root);
			root = NULL;
		}
		return root;
	}
	int index = key[depth] - 'a' ;
	root->children[index] =
	remove (root->children[index], key, depth + 1);
	if (isEmpty(root) && root->isLeaf == false ) 
	{
		delete (root);
		root = NULL;
	}
	return root;
}

bool search( struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;
	for ( int i = 0; i < key.length(); i++) 
	{
		int index = key[i] - 'a' ;
		if (!pCrawl->children[index])
			return false ;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isLeaf);
}

void suggestionsRec( struct TrieNode* root, string currPrefix)
{
	if (root->isLeaf)
	{
		cout << currPrefix;
		cout << endl;
	}
	if (isEmpty(root))
		return ;
	for ( int i = 0; i < alpha_size; i++)
	{
		if (root->children[i])
		{
			currPrefix.push_back(97 + i);
			suggestionsRec(root->children[i], currPrefix);
			currPrefix.pop_back();
		}
	}
}

int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;
	int level;
	int n = query.length();
	for (level = 0; level < n; level++)
	{
		int index = (int)query[level] - 'a';
		if (!pCrawl->children[index])
			return 0;
		pCrawl = pCrawl->children[index];
	}
	bool isWord = (pCrawl->isLeaf == true );
	bool isLast = isEmpty(pCrawl);
	if (isWord && isLast)
	{
		cout << query << endl;
		return -1;
	}
	if (!isLast)
	{
		string prefix = query;
		suggestionsRec(pCrawl, prefix);
		return 1;
	}
}

int main()
{
	char keys[][8] = { "the" , "a" , "there" , "answer" ,"any" , "by" , "bye" , "their" };
	struct TrieNode* root = new TrieNode;	// root = createNode();
	for(int i=0;i<alpha_size;i++)
		root->children[i] = NULL;
	for ( int j = 0; j < ARRAY_SIZE(keys); j++)
	root = insert_node(root, keys[j]);
	int level = 0;
	char str[20];
	cout << "Content of Trie: " << endl;
	display(root, str, level);
	
	int depth = 0;
	root = remove(root,"hero",depth);
	
	cout << "After Deletion Content of Trie: " << endl;
	display(root, str, level);
	
	cout<<"\nSearching:";
	search(root, "the" ) ? cout << "\nYes" : cout << "\nNo" ;
	search(root, "these" ) ? cout << "\nYes" : cout << "\nNo" ;
	
	/*
		AutoCompletion:
		For example if the Trie store {“abc”, “abcd”, “aa”, “abbbaba”} and the User types in “ab” then he must be shown {“abc”, “abcd”, “abbbaba”}.
	*/
	
	cout<<"\nAuto-Completion:";
	int comp = printAutoSuggestions(root, "a" );
	if (comp == -1)
		cout << "\nNo other strings found with this prefix\n" ;
	else if (comp == 0)
		cout << "\nNo string found with this prefix\n" ;
}





