#include <iostream>
#include <queue>
using namespace std;

class Sort
{
private:
    int a[20][20], res[30], v, e;
public:
    void input();
    void display();
    void sortDFS();
    void sortBFS();
    void topologicalSortDFS(int vertex, int visited[], int &index);
};

void Sort::input()
{
    cout << "Enter number of vertices: " << endl;
    cin >> v;
    cout << "Enter number of edges: " << endl;
    cin >> e;
    cout << "Enter adjacency matrix: " << endl;
    for (int i = 0; i < e; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
}

void Sort::display()
{
    for (int i = 0; i < v; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Sort::sortDFS()
{
    int visited[20] = {0}; 
    int index = v - 1; 
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            topologicalSortDFS(i, visited, index);
        }
    }
}

void Sort::topologicalSortDFS(int vertex, int visited[], int &index)
{
    visited[vertex] = 1;
    for (int i = 0; i < e; i++)
    {
        if (a[i][0] == vertex && visited[a[i][1]] == 0)
        {
            topologicalSortDFS(a[i][1], visited, index);
        }
    }
    res[index] = vertex;
    index--;
}

void Sort::sortBFS()
{
    int indeg[20] = {0};
    for (int i = 0; i < e; i++)
    {
        indeg[a[i][1]]++; 
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    int index = 0; 
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        res[index] = vertex; 
        index++; 
        for (int i = 0; i < e; i++)
        {
            if (a[i][0] == vertex)
            {
                indeg[a[i][1]]--;
                if (indeg[a[i][1]] == 0)
                {
                    q.push(a[i][1]);
                }
            }
        }
    }
}

int main()
{
    Sort s;
    s.input();

    cout << "Topological Sort using DFS: ";
    s.sortDFS();
    s.display();

    cout << "Topological Sort using BFS: ";
    s.sortBFS();
    s.display();

    return 0;
}
