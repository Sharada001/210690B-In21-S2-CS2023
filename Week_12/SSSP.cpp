#include <iostream>
#include<vector>
using namespace std;

void Format_output(vector<int> distance, int start_node) {
    cout << "The shortest distance from city " << start_node << " to all other cities is: " << endl;
    for (int i = 0; i < distance.size(); i++) {
        cout << "City " << i << ": " << distance[i] << endl;
    }
}

double Average_cost(vector<int> distance) {
    int total_distance = 0;
    for (int i = 0; i < distance.size(); i++) {
        total_distance += distance[i];
    }
    double num_nodes = distance.size() - 1;
    double average_distance = total_distance / num_nodes;
    cout << "The average traversal cost is: " << average_distance << endl << endl;
    return average_distance;
}

double Dijkstras_algorithm(int start_node, vector<vector<int>> adjacency_matrix) {
    int num_nodes = adjacency_matrix.size();
    vector<int> distance(num_nodes, INT_MAX);
    vector<bool> visited(num_nodes, false);
    int current_node = start_node;
    distance[start_node] = 0;
    while (true) {
        visited[current_node] = true;
        for (int i=0; i<num_nodes; i++) {
            if (adjacency_matrix[current_node][i] != 0) {
                if (distance[i] > distance[current_node] + adjacency_matrix[current_node][i]) {
                    distance[i] = distance[current_node] + adjacency_matrix[current_node][i];
                }
            }
        }
        int min = INT_MAX;
        for (int i=0; i<num_nodes; i++) {
            if (visited[i] == false && distance[i] < min) {
                current_node = i;
                min = distance[i];
            }
        }
        if (min == INT_MAX) {
            break;
        }
    }
    Format_output(distance, start_node);
    return Average_cost(distance);
}

void min_cost_source_node(vector<vector<int>> adjacency_matrix) {
    double min_cost = INT_MAX;
    vector<int> min_cost_nodes;
    double cost;
    for (int i=0; i<adjacency_matrix.size(); i++) {
        cost = Dijkstras_algorithm(i, adjacency_matrix);
        if (min_cost == cost) {
            min_cost_nodes.push_back(i);
        }
        else if (min_cost > cost) {
            min_cost_nodes.clear();
            min_cost_nodes.push_back(i);
            min_cost = cost;
        }
    }
    cout << "The cities with the minimum average traversal cost is: " ;
    for (int i=0; i<min_cost_nodes.size(); i++) {
        cout << min_cost_nodes[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adjacency_matrix = {
        {0, 10,	0,	0,	15,	5},
        {10, 0, 10, 30, 0, 0},
        {0,	10,	0,	12,	5,	0},
        {0,	30,	12,	0,	0,	20},
        {15, 0,	5,	0,	0,	0},
        {5,	0,	0,	20,	0,	0}
    };
    min_cost_source_node(adjacency_matrix);
    // Dijkstras_algorithm(5, adjacency_matrix);
}