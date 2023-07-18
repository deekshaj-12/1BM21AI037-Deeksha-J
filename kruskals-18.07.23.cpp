#include <iostream>

using namespace std;

class Graph {
private:
    int V;
    int adjMatrix[100][100];

public:
    void initialize(int numVertices);
    void addEdge(int src, int dest, int weight);
    void KruskalMST();
    void clear();
};

void Graph::initialize(int numVertices) {
    V = numVertices;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight;
}

void Graph::KruskalMST() {
    bool visited[100];
    pair<int, int> edges[100];
    int totalWeight = 0;

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    visited[0] = true;

    for (int i = 1; i < V; ++i) {
        int minWeight = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < V; ++j) {
            if (visited[j]) {
                for (int k = 0; k < V; ++k) {
                    if (!visited[k] && adjMatrix[j][k] != 0 && adjMatrix[j][k] < minWeight) {
                        minWeight = adjMatrix[j][k];
                        minIndex = k;
                    }
                }
            }
        }

        if (minIndex != -1) {
            visited[minIndex] = true;
            edges[i] = make_pair(minIndex, minWeight);
            totalWeight += minWeight;
        }
    }

    cout << "Edges in the minimum spanning tree:\n";
    for (int i = 1; i < V; ++i) {
        cout << "0 - " << edges[i].first << " : " << edges[i].second << "\n";
    }

    cout << "Total weight of the minimum spanning tree: " << totalWeight << endl;
}

void Graph::clear() {
    V = 0;
}

int main() {
    Graph g;

    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    g.initialize(numVertices);

    cout << "Enter the edges (src, dest, weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    g.KruskalMST();

    g.clear();

    return 0;
}
