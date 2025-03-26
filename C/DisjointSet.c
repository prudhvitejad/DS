#include <stdio.h>
#include <stdlib.h>

struct DisjointSet
{
    int *parent;
    int *rank;
    int *size;  // Stores the size of each set
    int totalSets;  // Counts the number of sets
    int n;
};

// Create a disjoint set with `n` elements
struct DisjointSet* createSet(int n) 
{
    struct DisjointSet *ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    ds->n = n;
    ds->totalSets = n;  // Initially, every element is its own set
    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));
    ds->size = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        ds->parent[i] = i;  // Initially each element is its own parent
        ds->rank[i] = 0;     // Rank is initially 0
        ds->size[i] = 1;     // Each set starts with 1 element
    }
    return ds;
}

// Find with Path Compression
int find(struct DisjointSet *ds, int x) 
{
    if (ds->parent[x] != x)
        ds->parent[x] = find(ds, ds->parent[x]);  // Path compression
    return ds->parent[x];
}

// Union by Rank & Size Update
void unionSets(struct DisjointSet *ds, int x, int y) 
{
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    //If they're already in the same set, no need to union
    if (rootX != rootY) 
    {
        // Attach smaller tree under larger tree
        if (ds->rank[rootX] > ds->rank[rootY]) 
        {
            ds->parent[rootY] = rootX;
            ds->size[rootX] += ds->size[rootY]; // Merge sizes
        }
        else if (ds->rank[rootX] < ds->rank[rootY]) 
        {
            ds->parent[rootX] = rootY;
            ds->size[rootY] += ds->size[rootX]; // Merge sizes
        }
        else
        {
            ds->parent[rootY] = rootX;
            ds->size[rootX] += ds->size[rootY]; // Merge sizes
            ds->rank[rootX]++;
        }
        ds->totalSets--; // Reduce set count
    }
}

// Count the number of sets
int countSets(struct DisjointSet *ds) 
{
    return ds->totalSets;
}

// Print the size of each set
void printSetSizes(struct DisjointSet *ds) 
{
    printf("Set Sizes:\n");
    for (int i = 0; i < ds->n; i++) 
    {
        if (ds->parent[i] == i) // Root nodes represent unique sets
            printf("Set with root %d has %d elements\n", i, ds->size[i]);
    }
}

// Print the parent array for debugging
void printSet(struct DisjointSet *ds) 
{
    printf("Element: ");
    for (int i = 0; i < ds->n; i++)
        printf("%d ", i);
    
    printf("\nParent : ");
    for (int i = 0; i < ds->n; i++)
        printf("%d ", ds->parent[i]);
  
    printf("\n");
}

int main()
{
    int n = 6;
    struct DisjointSet *ds = createSet(n);

    printf("Initial Disjoint Set:\n");
    printSet(ds);
    printf("Total Sets: %d\n\n", countSets(ds));

    unionSets(ds, 0, 2);
    unionSets(ds, 4, 2);
    unionSets(ds, 3, 1);
    
    printf("After Union Operations:\n");
    printSet(ds);
    printf("Total Sets: %d\n\n", countSets(ds));

    printSetSizes(ds);

    // Cleanup
    free(ds->parent);
    free(ds->rank);
    free(ds->size);
    free(ds);
    
    return 0;
}
