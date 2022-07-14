#include <iostream>
#include <vector>
#include <cstring> // use memset

using namespace std;
#define RED  1
#define BLUE 2

int k, v, e;

vector<int> graph[20001];
int visited[20001];

void dfs(int k){
	if (!visited[k]) {
        visited[k] = RED;
    }
	
	for(int i = 0; i < graph[k].size(); ++i){
		int num = graph[k][i];
		if(visited[num] == false){
			if (visited[k] == RED){
                visited[num] = BLUE;
            }
            else if (visited[k] == BLUE){
            	visited[num] = RED;
            }
			dfs(num);		
		}
	}
}

bool isBipartiteGraph(){
	for(int i = 1; i <= v; ++i){
		for(int j = 0; j < graph[i].size(); ++j){
			int next = graph[i][j];
			if(visited[i] == visited[next])
				return false;
		}
	}
	return true;
}

int main(){

	//
	/*
	k 테스트 케이스 개수
	v 정점의 개수
	e 간선의 개수
	*/
	
	cin >> k;
	
	for(int q = 0; q < k; ++q){
		cin >> v >> e;
		for(int i = 0; i < e; ++i){
			int st,en;
			cin >> st >> en;
			graph[st].push_back(en);
			graph[en].push_back(st);
		}

		for (int i = 1; i <= v; i++){ 
            if (!visited[i]){
                dfs(i);
            } 
        }

		if(isBipartiteGraph())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		for(int i = 0; i <= v; ++i){
			graph[i].clear();
		}
		memset(visited, false, sizeof(visited));
	}
	
	
	
	
	return 0;
}