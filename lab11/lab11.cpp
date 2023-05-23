#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 6

int min_key(int key[], bool mst_set[])
{
    // Initialize min value
    int minimum = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mst_set[v] == false && key[v] < minimum)
            minimum = key[v], min_index = v;

    return min_index;
}


void print_MST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int num = 1; num < V; num++)
        cout << parent[num] << " - " << num << " \t"
             << graph[num][parent[num]] << " \n";
}


void prim_MST(int graph[V][V])
{
    
    //To store the constructed MST, array.
    int parent[V];

    // The key values are employed for selecting the edge with the minimum weight in a cut.
    int key[V];

    // In order to denote the collection of vertices encompassed within the minimum spanning tree
    bool mst_set[V];

    // The initialization of all keys as "INFINITE" is undertaken.
    for (int val = 0; val < V; val++)
        key[val] = INT_MAX, mst_set[val] = false;

    key[0] = 0;

    // The initial node is consistently designated as the root of the minimum spanning tree
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        // Pick the minimum key vertex from the set of vertices not  yet included in MST
        int u = min_key(key, mst_set);

        mst_set[u] = true;


        for (int v = 0; v < V; v++)

            if (graph[u][v] && mst_set[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    print_MST(parent, graph);
}

//main
int main()
{
    int graph[V][V] ={{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
    prim_MST(graph);

    return 0;
}