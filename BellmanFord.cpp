#include <iostream>
using namespace std;

class Graph{
    int V;
    int** graph;

public:
    Graph(int vertices){
        V = vertices;
        graph = new int*[V];
        for (int i = 0; i < V; i++){
            graph[i] = new int[V];
            for (int j = 0; j < V; j++)
                graph[i][j] = 0;
        }
    }

    void addEdge(int u, int v, int w){
        graph[u-1][v-1] = w;
    }

    void printGraph(){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++)
                cout << graph[i][j] << " ";
            cout<<endl;
        }
    }

    int bellmanFord(int src, int dest){
        int* dist = new int[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[src-1] = 0;

        for (int i = 1; i < V; i++){
            for (int u = 0; u < V; u++){
                for (int v = 0; v < V; v++){
                	
                    if (graph[u][v] != 0){
                        int wt = graph[u][v];
                        if (dist[u] != INT_MAX && (dist[u] + wt) < dist[v]){
                            dist[v] = dist[u] + wt;
                        }
                    }
                }
            }
        }

        bool flag = false;
        for (int u = 0; u < V; u++){
            for (int v = 0; v < V; v++){
                if (graph[u][v] != 0) {
                    int wt = graph[u][v];
                    if (dist[u] != INT_MAX && (dist[u] + wt) < dist[v]){
                        flag = true;
                    }
                }
            }
        }

        if (flag == true){
            cout << "graph has negative cycle" << endl;
            return -1;
        }
        else{
            cout << "no negative cycles" << endl;
            return dist[dest-1];
        }
    }
};
int main(){
    int n = 3; // vertices
    Graph g(n);

    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, -1);
    g.addEdge(3, 1, 2);

    int src = 1;
    int dest = 3;
    int distance = g.bellmanFord(src, dest);

    if (distance != -1) {
        cout << "distance from "<<src<<" to "<<dest <<" is "<<distance<<endl;
    }
}
