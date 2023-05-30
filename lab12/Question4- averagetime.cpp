#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <iomanip>


#define INF INT_MAX // Infinity

// Structure to represent a node and its distance from the source
struct Node {
    int index;
    int distance;

    Node(int i, int d) : index(i), distance(d) {}
};

// Comparison operator- priority queue 
struct Compare_node {
    bool operator()(const Node& node_1, const Node& node_2) {
        return node_1.distance > node_2.distance;
    }
};

// Dijkstra's algorithm 
void dijkstra_shortest_paths(std::vector<std::vector<int>>& graph, int source) {
    int num_nodes = graph.size(); // Number of nodes
    std::vector<int> distances(num_nodes, INF); // shortest distance values array
    std::vector<bool> visited(num_nodes, false); // visited nodes array

    distances[source] = 0; // Distance from source to itself 

    // Priority queue to store nodes with their distances
    std::priority_queue<Node, std::vector<Node>, Compare_node> pr_q;
    pr_q.push(Node(source, 0));

    while (!pr_q.empty()) {
        int u = pr_q.top().index;
        pr_q.pop();

        // Skip the nodes which have already been visited
        if (visited[u])
            continue;

        visited[u] = true;

        // Iteration - through all adjacent nodes of u
        for (int v = 0; v < num_nodes; v++) {
            // Update  if there is a shorter path
            if (!visited[v] && graph[u][v] != INF &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pr_q.push(Node(v, distances[v]));
            }
        }
    }

    int total = 0;
    
    for (int v = 0; v < num_nodes; v++) {
        total+=distances[v];
        std::cout << "Source City " << v << ": " << distances[v] << "\n";
    }
    float average= total/5.0;
    std::cout<<std::fixed << std::setprecision(2)<< "Average time "<<average<< "\n";

}

int main() {
    // weighted adajaceny matrix for the graph on Fig 1. in Lab12 CS2023 
    std::vector<std::vector<int>> graph = {
        {0, 10,INF, INF,15,5},
        {10, 0,10, 30, INF, INF},
        {INF,10, 0, 12, 5, INF},
        {INF, 30, 12, 0, INF, 20},
        {15, INF, 5, INF, 0, INF},
        {5, INF, INF, 20, INF, 0}
    };

    int source;
    std::cout << "Enter the source node: ";
    std::cin >> source;

    dijkstra_shortest_paths(graph, source); //call the algorithm

    return 0;
}
