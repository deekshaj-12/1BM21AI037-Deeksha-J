#include <iostream>

using namespace std;

class Graph {
private:
    int V;
    int** adjMatrix;

public:
    void initialize(int numVertices) {
        V = numVertices;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; ++i) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    void KruskalMST() {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        pair<int, int>* edges = new pair<int, int>[V];
        int totalWeight = 0;

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

        delete[] visited;
        delete[] edges;
    }

    void clear() {
        for (int i = 0; i < V; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        V = 0;
    }
};

int main() {
    Graph graph;

    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    graph.initialize(numVertices);

    cout << "Enter the edges (src, dest, weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.KruskalMST();

    graph.clear();

    return 0;
}
