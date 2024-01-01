#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // 무한대 값

void floydWarshall(vector<vector<int>>& graph, int V) {
	
	vector<vector<int>> dist(V, vector<int>(V, 0));
	for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }
	
	// 모든 정점을 중간 정점으로 선택하여 최단 경로 갱신
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && 
					dist[k][j] != INF && 
					dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
					//adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
	
	// 결과 출력
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int V, E; // 정점 수와 간선 수
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // 그래프 초기화 (인접 행렬 사용)
    vector<vector<int>> graph(V, vector<int>(V, INF));
    cout << "Enter the edges and their weights (format: u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // 플로이드-와샬 알고리즘 호출
    floydWarshall(graph, V);

    return 0;
}