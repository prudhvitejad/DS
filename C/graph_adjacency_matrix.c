// This is for Adjacency Matrix 

#include <stdio.h>
#include <stdlib.h>
#define max 10

int Queue[max];
int rear=-1,front=-1;
	 
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
	
	BFSTraversal(G,visited);
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


void BFSTraversal(struct Graph *G,int visited[])
{
	for(int i=0;i<G->vertices;i++)
		visited[i] = 0;
		
	for(int i=0;i<G->vertices;i++)
	{
		if(!visited[i])
			BFS(G,i,visited);
	}
}


BFS(struct Graph *G,int u,int visited[])
{
	Enqueue(u);
	
	while(!isEmptyQueue())
	{
		u = Dequeue();
		printf("%c\t",u+65);
		
		visited[u] = 1;
		
		for(int i=0;i<G->vertices;i++)
		{
			if(!visited[i] && G->Adj[u][i])
			{
				if(!(isInQueue(i)))	// Searching for 
				{
					Enqueue(i);
				}
			}
		}
	}
}


void Enqueue(int root)
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


int Dequeue()
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

int isInQueue(int key)
{
	if(!isEmptyQueue)
	{
		int i;
		for(i=front;i<rear;i=(i+1)%max)
		{
			if(Queue[i] == key)
			printf("\nInside Loop");
				return 1;
		}
		if(Queue[i] == key)
		{
			printf("\nInside if");	
			return 1;
		}
		else
		{
			printf("\nInside else");
			return 0;
		}
	}
	else	
		printf("\nInside outer else");
		return 2;
}














