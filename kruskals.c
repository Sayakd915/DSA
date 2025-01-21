#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent an edge
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

// Structure to represent a disjoint set
typedef struct {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} DisjointSet;

// Function to find the root of a node in the disjoint set
int find(DisjointSet *set, int node) {
    if (set->parent[node] != node) {
        set->parent[node] = find(set, set->parent[node]);
    }
    return set->parent[node];
}

// Function to union two nodes in the disjoint set
void unionSet(DisjointSet *set, int node1, int node2) {
    int root1 = find(set, node1);
    int root2 = find(set, node2);

    if (set->rank[root1] < set->rank[root2]) {
        set->parent[root1] = root2;
    } else if (set->rank[root1] > set->rank[root2]) {
        set->parent[root2] = root1;
    } else {
        set->parent[root2] = root1;
        set->rank[root1]++;
    }
}

// Function to compare two edges
int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;

    return edge1->weight - edge2->weight;
}

// Function to implement Kruskal's algorithm
void kruskal(Edge edges[], int numEdges, int numVertices) {
    DisjointSet set;
    int i, j, k;

    // Initialize the disjoint set
    for (i = 0; i < numVertices; i++) {
        set.parent[i] = i;
        set.rank[i] = 0;
    }

    // Sort the edges in non-decreasing order of their weights
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // Initialize the MST
    int mstEdges = 0;
    printf("Edge \tWeight\n");

    // Iterate over the sorted edges
    for (i = 0; i < numEdges; i++) {
        int source = edges[i].source;
        int destination = edges[i].destination;
        int weight = edges[i].weight;

        // Check if the edge forms a cycle
        if (find(&set, source) != find(&set, destination)) {
            // Add the edge to the MST
            printf("%d - %d \t%d \n", source, destination, weight);
            mstEdges++;

            // Union the two nodes in the disjoint set
            unionSet(&set, source, destination);

            // If we have found the required number of edges, break
            if (mstEdges == numVertices - 1) {
                break;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Edge edges[MAX_EDGES];
    int i;

    // Read the edges
    for (i = 0; i < numEdges; i++) {
        printf("Enter the source, destination, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    // Implement Kruskal's algorithm
    kruskal(edges, numEdges, numVertices);

    return 0;
}
