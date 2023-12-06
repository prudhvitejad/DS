#include <stdio.h>
#include <stdlib.h>

struct Graph
{
	int vertices;
	int edges;
	int **Adj;		// since we need 2 dimensional matrix
};

struct Graph* adjMatrixOfGraph();

int main()
{
	struct Graph *G = adjMatrixOfGraph(); 
	
	int visited[G->vertices];
	
	DFSTraversal(G,visited);
}


// This code creates a graph with adjacent matrix representation
struct Graph* adjMatrixOfGraph() 
{
	int i,u,v;
	
	struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph)); // Memory Allocation for the node
	
	if(!G)
	{
		printf("\nMemory Error");
		return;
	}
	
	printf("\nNumber of Vertices and Edges:");
	scanf("%d %d",&G->vertices,&G->edges);
	
	G->Adj = (int**)malloc(G->vertices*sizeof(int*));	// Memory Allocation for the Adjacency Matrix
	
	if(G->Adj == NULL)
	{
		printf("\nMemory Error");
		return;
	}
	for(int j=0;j<G->vertices;j++)
	{
		G->Adj[j] = (int*)malloc(G->vertices*sizeof(int));		// Memory Allocation for the Adjacency Matrix
		
		if(G->Adj[j] == NULL)
		{
			printf("\nMemory Error");
			return;
		}
	}
	
	for(u=0;u<G->vertices;u++)		// Initialization of Adjacency Matrix
	{
		for(v=0;v<G->vertices;v++)
			G->Adj[v][v] = 0;
	}
	
	for(i=0;i<G->edges;i++)	// Reading edges
	{
		printf("\nEdge from which vertex to which vertex:");
		scanf("%d %d",&u,&v);
		
		G->Adj[u][v] = G->Adj[v][u] = 1; // For undirected graphs set both the bits
		
		/*
			G->Adj[u][v] = 1; // For directed graphs set one bit only
			
		*/
	}
	
	return G;
}



void DFS(struct Graph *G,int u,int visited[])
{
	printf("%c\t",u+65);
	visited[u] = 1;
	
	for(int v=0;v<G->vertices;v++)
	{
		if(!visited[v] && G->Adj[u][v])
		{
			DFS(G,v,visited);
		}
	}
		
}


void DFSTraversal(struct Graph *G,int visited[])
{
	for(int i=0;i<G->vertices;i++)
		visited[i] = 0;
	
	// This loop is required if the graph has more than one component
	
	for(int i=0;i<G->vertices;i++)
	{
		if(!visited[i])
			DFS(G,i,visited);
	}
}

























