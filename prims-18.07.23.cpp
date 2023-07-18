#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX_VERTICES = 100;

class Graph {
private:
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];

public:
    void init(int n);
    void addEdge(int u, int v, int w);
    void primMST();
    int findMinWeightVertex(int mw[], int visited[]);
    void clear();
};

void Graph::init(int n) {
    V = n;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w;
}

void Graph::primMST() {
    int visited[MAX_VERTICES];
    int mw[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int i = 0; i < V; ++i) {
        visited[i] = 0;
        mw[i] = INF;
    }

    mw[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; ++i) {
        int minIndex = findMinWeightVertex(mw, visited);

        visited[minIndex] = 1;

        for (int j = 0; j < V; ++j) {
            if (adj[minIndex][j] != 0 && !visited[j] && adj[minIndex][j] < mw[j]) {
                mw[j] = adj[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    cout << "Edges in the minimum spanning tree:\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << adj[i][parent[i]] << "\n";
    }
}

int Graph::findMinWeightVertex(int mw[], int visited[]) {
    int minVal = INF;
    int minIndex = -1;

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && mw[i] < minVal) {
            minVal = mw[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void Graph::clear() {
    V = 0;
}

int main() {
    Graph g;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    g.init(V);

    cout << "Enter the edges (u, v, w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();

    g.clear();

    return 0;
}
