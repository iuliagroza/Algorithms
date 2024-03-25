// This code was contributed by Riyazul555 and iuliagroza

// Time Complexity = O(f * (V + E))   where V is the total number of nodes in the graph, E is the total number of edges in the graph, f is the Maximum flow
// Space Complexity = O(V^2)          where V is the total number of nodes in the graph, E is the total number of edges in the graph, f is the Maximum flow

#include <fstream>
#include <vector>
#include <queue>
#define nMax 1005

using namespace std;

int C[nMax][nMax];

int bfs(vector<int> G[nMax], int n, int dad[nMax])
{
    queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int nod=Q.front();
		Q.pop();
		for(int i:G[nod])
			if (!dad[i] && C[nod][i]>0)
			{
				dad[i]=nod;
				Q.push(i);
			}
	}
	return dad[n];
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	int n, m;
	fin >> n >> m;
	vector<int> G[nMax];


	for(int i=1; i<=m; i++)
	{
	    int x, y, c;
		fin >> x >> y >> c;
		x++;
		y++;
		C[x][y]=c;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int flow = 0, dad[nMax]={0};
	while(bfs(G, n, dad))
	{
		for(auto i:G[n])
		{
			int Min=C[i][n];
			for(int j=i; j!=1; j=dad[j])
				Min=min(Min, C[dad[j]][j]);
			for(int j=i; j!=1; j=dad[j])
				C[dad[j]][j]-=Min, C[j][dad[j]]+=Min;

			flow+=Min;
			C[i][n]-=Min;
			C[n][i]+=Min;
		}
		fill(dad, dad+n+1, 0);
	}
    fout << flow;
	return 0;
}
