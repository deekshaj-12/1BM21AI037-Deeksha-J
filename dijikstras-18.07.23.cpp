#include <iostream>

using namespace std;

class Dijkstra {
private:
    int V;  
    int graph[100][100]; 
    int dist[100];     
    bool visited[100];   
    const int INFINITY = 99999;

public:
    Dijkstra(int V);
    void addEdge(int src, int dest, int weight);
    void findShortestPath(int src);
    void printShortestPath(int src);
};

Dijkstra::Dijkstra(int V) {
    this->V = V;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            graph[i][j] = 0;
        dist[i] = INFINITY;
        visited[i] = false;
    }
}

void Dijkstra::addEdge(int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = weight; 
}

void Dijkstra::findShortestPath(int src) {
    dist[src] = 0;
    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] != 0) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }
}

void Dijkstra::printShortestPath(int src) {
    cout << "Shortest paths from node " << src << " to all other nodes:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INFINITY) {
            cout << "Not reachable\n";
        } else {
            cout << dist[i] << " units away\n";
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    Dijkstra dijkstra(numNodes);

    cout << "Enter the vertice numbers and the weight between them:\n";
    for (int i = 0; i < numEdges; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        dijkstra.addEdge(v1, v2, w);
    }

    int sourceNode = 0;
    dijkstra.findShortestPath(sourceNode);
    dijkstra.printShortestPath(sourceNode);

    return 0;
}
