#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // 정점의 개수
    vector<vector<int>> adj; // 인접 리스트

public:
    Graph(int v) : V(v), adj(v) {}

    // 유향 그래프에 간선 추가
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // 위상 정렬 수행
    void topologicalSort() {
        vector<int> inDegree(V, 0); // 각 정점의 진입 차수
        queue<int> q;

        // 진입 차수 계산
        for (int v = 0; v < V; ++v) {
            for (int w : adj[v]) {
                inDegree[w]++;
            }
        }

        // 진입 차수가 0인 정점을 큐에 추가
        for (int v = 0; v < V; ++v) {
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }

        // 위상 정렬 수행
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int w : adj[v]) {
                // 인접 정점의 진입 차수 감소
                inDegree[w]--;

                // 진입 차수가 0이 되면 큐에 추가
                if (inDegree[w] == 0) {
                    q.push(w);
                }
            }
        }
    }
};


int main(){
	
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort: ";
    g.topologicalSort();
	
	return 0;
}

/*
위상 정렬

일들의 선행 조건들을 만족시키면서 수행 순서를 정한다.

7개의 필수 과목들 1,2,3,4,5,6,7
과목들 간의 선후수 관계
1. 2의 선수과목 = 1
2. 4의 선수 과목 = 1,2,3
3. 5의 선수 과목 = 3
4. 6의 선수 과목 = 2,4,5
5. 7의 선수 과목 = 5,6
A가 B의 선수 과목이면 간선(A->B)를 방향 그래프에 추가한다.

방향 그래프에 순환이 없어야 한다.
순환이 있는지는 깊이 우선 탐색을 이용하여 알 수 있다.
깊이 우선 탐색과 스택을 이용
탐색 중 한 정점 v에 인접한 방문 안한 정점 w가 있으면
정점 w를 방문함으로 표시하고 w를 v로 하여 깊이 우선 탐색을 계속한다.
만약 정점 v에 인접한 방문하지 않은 정점들이 없으면 v를 스택에 집어 넣는다
탐색이 종료되면 스택에 있는 정점들을 하나씩 출력한다.
처음에 그래프에 시작 정점 s를 추가하고 s에서 진입 간선이 없는 정점으로 가는 간선을 추가한다.
*/