#include <iostream>
#include <vector>
using namespace std;


vector<int> Prims_algorithm(vector<vector<int>> graph, int start) {

    // graph is a 2D vector containing the adjacency matrix of the graph
    int num_nodes = graph.size();
    // min_dist[i] is the minimum distance from i to any node in the MST
    vector<int> min_dist(num_nodes, INT_MAX);
    // visited[i] is true if node i is already in the MST
    vector<bool> visited(num_nodes, false);
    // parent[i] is the parent of node i in the MST
    vector<int> parent(num_nodes, -1);

    // set the distance of the start node to 0
    min_dist[start] = 3;
    
    for (int i = 0; i < num_nodes; i++) {
        int choosen_node = -1;
        for (int j = 0; j < num_nodes; j++) {
            // find the node with the minimum distance from the MST
            if (!visited[j] && (choosen_node == -1 || min_dist[j] < min_dist[choosen_node])) {
                choosen_node = j;
            }
        }
        // mark the node as visited
        visited[choosen_node] = true;
        for (int neighbor_node = 0; neighbor_node < num_nodes; neighbor_node++) {
            // update the distance of the neighbours of u
            if (!visited[neighbor_node] && graph[choosen_node][neighbor_node] != 0 && graph[choosen_node][neighbor_node] < min_dist[neighbor_node]) {
                min_dist[neighbor_node] = graph[choosen_node][neighbor_node];
                parent[neighbor_node] = choosen_node;
            }
        }
    }
    return parent;
}

void print_parent(vector<int> parent) {
    // print the parent(neighbor) of each node in the MST
    cout <<"\nVertex\tParent\n";
    for (int i = 0; i < parent.size(); i++) {
        if (parent[i] == -1) {
            continue;
        }
        cout << i << "\t" << parent[i] << endl;
    }
    cout << endl;
}



int main() {
    vector<vector<int>> graph;
    graph.push_back({ 0, 3, 0, 0, 0, 1 });
    graph.push_back({ 3, 0, 2, 1, 10, 0 });
    graph.push_back({ 0, 2, 0, 3, 0, 5 });
    graph.push_back({ 0, 1, 3, 0, 5, 0 });
    graph.push_back({ 0, 10, 0, 5, 0, 4 });
    graph.push_back({ 1, 0, 5, 0, 4, 0 });
    vector<int> parent = Prims_algorithm(graph, 0);
    print_parent(parent);
    return 0;
}