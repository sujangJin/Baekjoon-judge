#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph{
public:
	int N; // 정점의 개수
	vector<vector<int>> adj; // 인접 리스트
	vector<bool> visited;	// 방문 여부를 저장하는 배열

	// 생성자
	Graph() : N(0){}
	Graph(int n) : N(n){
		adj.resize(N);
		visited.resize(N);
	}

	// 간선 추가 함수
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 모든 리스트의 인접한 정점 번호 정렬
	void sortList(){
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	// 깊이 우선 탐색
	void dfs(){
		fill(visited.begin(), visited.end(), false);
		dfs(0);
	}

	

	// 모든 컴포넌트(덩어리)를 접근하는 깊이 우선 탐색
	int dfsAll(){
		int components = 0;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < N; i++){
			if (!visited[i]){
				cout << "-- new DFS begin --" << endl;
				// step2. 각 컴포넌트의 크기(정점의 개수)
				int nodes = dfs(i);
				components++;
				cout << "size " << nodes << endl << endl;
			}
		}
		return components;
	}

private:
	/*void dfs(int curr){
		visited[curr] = true;
		cout << "node " << curr << " visited" << endl;
		for (int next : adj[curr])
			if (!visited[next]) dfs(next);
	}*/

	// 깊이 우선 탐색 step2. 컴포넌트의 크기(정점의 개수) 구하기
	int dfs(int curr){
		int nodes = 1;
		visited[curr] = true;
		cout << "node " << curr << " visited" << endl;
		for (int next : adj[curr]){
			if (!visited[next]) nodes += dfs(next);
		}
		return nodes;
	}
};

int main(){
/*	예제1. 하나의 컴포넌트로 이루어진 그래프 구조
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	G.dfs();
*/
	Graph G(10);
	G.addEdge(0, 1);
	G.addEdge(1, 3);
	G.addEdge(2, 3);
	G.addEdge(4, 6);
	G.addEdge(5, 7);
	G.addEdge(5, 8);
	G.addEdge(7, 8);
	G.sortList();
	
	int components = G.dfsAll();
	cout << "The number of component is " << components << endl;

	return 0;
}