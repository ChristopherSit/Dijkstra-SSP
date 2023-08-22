#include <iostream>
#include <fstream>
#include <vector>
#include "Heap.cpp"

using namespace std;

vector<vector<pair<int, int>>> read_graph(string filename) {
    int n;
    ifstream infile(filename);
    infile >> n;
    vector<vector<pair<int, int>>> adj_list(n+1);

    int i, j, w;
    while (infile >> i >> j >> w) {
        adj_list[i].push_back({j, w});
    }

    // Print out the adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto& p : adj_list[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return adj_list;
}

vector<int> dijkstra(vector<vector<pair<int, int>>> adj_list, int src) {
    // Number of vertices in the graph
    int numVertex = adj_list.size()-1;
    // Set the initial value of all distances to something i know is larger than what is possible (100 or any really big number)
    vector<int> distance(numVertex+1, 100);
    vector<int> parent(numVertex+1, -1);
    // Set default distance to source as 0
    distance[src] = 0;

    Heap heap(distance, numVertex+1);

    while (!heap.is_empty()) {
        // Extract vertex with minimum distance from heap
        int minID = heap.min_id();
        heap.delete_min(); 
        for (auto& p : adj_list[minID]) {
            // Get the neighbor vertex id and weight
            int vertexWeight = p.second;
            int vertex = p.first;

            // Check if we can get a better distance
            if (distance[minID] + vertexWeight < distance[vertex] ) {
                // Update the distance to the neighbor vertex
                distance[vertex] = distance[minID] + vertexWeight;
                // Set the parent of the neighbor vertex to the new vertex
                parent[vertex] = minID;
                // Update the heap with the new distance of the neighbor vertex
                heap.decrease_key(vertex, distance[vertex]);
            }
        }
    }
    return distance;
}

int main(int argc, char* argv[]) {
    vector<vector<pair<int, int>>> adj_list = read_graph(argv[1]);
    vector<int> dist = dijkstra(adj_list, 1);

    for (int x = 1; x < dist.size(); x++) {
        cout << "Shortest distance from vertex 1 to vertex " << x << " is " << dist[x] << endl;
    }
}
