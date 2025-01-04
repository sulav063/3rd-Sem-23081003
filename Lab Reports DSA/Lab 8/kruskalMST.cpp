#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// Function to find the subset of an element 'i'
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparator function to sort edges by their weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find MST using Kruskal's algorithm
void KruskalMST(Edge edges[], int V, int E) {
    sort(edges, edges + E, compare);

    Edge result[V];
    int parent[V];

    // Initialize all subsets as single element sets
    fill(parent, parent + V, -1);

    int e = 0, i = 0; // indexes for result[] and edges[]

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    cout << "Edges of MST:" << endl;
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " : " << result[i].weight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Edge edges[E];
    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; ++i)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    KruskalMST(edges, V, E);

    return 0;
}
