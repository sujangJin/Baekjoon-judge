#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph{
public:
	int N; // ������ ����
	vector<vector<int>> adj; // ���� ����Ʈ
	vector<bool> visited;	// �湮 ���θ� �����ϴ� �迭

	// ������
	Graph() : N(0){}
	Graph(int n) : N(n){
		adj.resize(N);
		visited.resize(N);
	}

	// ���� �߰� �Լ�
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// ��� ����Ʈ�� ������ ���� ��ȣ ����
	void sortList(){
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	// ���� �켱 Ž��
	void dfs(){
		fill(visited.begin(), visited.end(), false);
		dfs(0);
	}

	

	// ��� ������Ʈ(���)�� �����ϴ� ���� �켱 Ž��
	int dfsAll(){
		int components = 0;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < N; i++){
			if (!visited[i]){
				cout << "-- new DFS begin --" << endl;
				// step2. �� ������Ʈ�� ũ��(������ ����)
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

	// ���� �켱 Ž�� step2. ������Ʈ�� ũ��(������ ����) ���ϱ�
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
/*	����1. �ϳ��� ������Ʈ�� �̷���� �׷��� ����
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