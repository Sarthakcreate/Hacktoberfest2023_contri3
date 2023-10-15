// Depth First Search Algorithm in Cpp

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void DFS(int source) {
        vector<bool> visited(V, false);
        stack<int> stack;
        stack.push(source);

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();
            
            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;
            }
            for (int neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
};
int main() {
    // Create a graph
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    cout << "Depth-First Search starting from vertex 2: ";
    graph.DFS(2);
    return 0;
}
