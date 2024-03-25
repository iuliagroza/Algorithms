// This code is contributed by Riyazul555 and iuliagroza

// Time Complexity  = O(V²*logV + VE) where where V is the number of vertices and E is the number of edges
// Space Complexity = O(V²)           where where V is the number of vertices and E is the number of edges        


#include <fstream>
#include <vector>
#include <queue>
#define nMax 1005

using namespace std;

void bf(int nod, int n, int h[], vector<pair<int, int>> G[nMax], bool &ok)
{
    queue<int> Q;
    bool in[nMax]={0};
    int nr[nMax]={0};
    for(int i=0; i<n; i++)
        h[i]=1e9;
    h[nod]=0;
    Q.push(nod);
    in[nod]=1;
    while(!Q.empty())
    {
        nod=Q.front();
        Q.pop();
        in[nod]=0;
        for(auto i:G[nod])
            if(h[nod]+i.second<h[i.first])
            {
                h[i.first]=h[nod]+i.second;
                nr[i.first]++;
                if(nr[i.first]>n)
                {
                    ok=1;
                    return;
                }
                if(!in[i.first])
                {
                    in[i.first]=1;
                    Q.push(i.first);
                }
            }
    }

}

void dijkstra(int nod, int n, int d[], vector<pair<int, int>> G[nMax])
{
    priority_queue<pair<int, int>> Q;
    bool in[nMax]={0};
    Q.push({0, nod});
    for(int i=0; i<n; i++)
        if(i!=nod)
        {
            d[i]=-1e9;
            Q.push({d[i], i});
        }
    d[nod]=0;
    while(!Q.empty())
    {
        if(!in[Q.top().second])
        {
            int x=Q.top().second;
            for(auto i:G[x])
                if(d[x]-i.second>d[i.first])
            {
                Q.push({d[x]-i.second, i.first});
                d[i.first]=d[x]-i.second;
            }
            in[x]=1;
        }
        else
            Q.pop();
    }
}

int main(int argc, char * argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, m;
    vector<pair<int, int>> G[nMax];
    fin >> n >> m;
    while(m--)
    {
        int x, y, w;
        fin >> x >> y >> w;
        G[x].push_back({y, w});
    }
    int s=n;
    for(int i=0; i<n; i++)
        G[s].push_back({i, 0});
    int h[nMax]={0};
    bool ok=0;
    bf(s, n, h, G, ok);
    if(ok)
        fout << -1;
    else
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<G[i].size(); j++)
            {
                G[i][j].second += h[i]-h[G[i][j].first];
                fout << i << " " << G[i][j].first << " " << G[i][j].second << "\n";
            }
        int d[nMax]={0};
        for(int i=0; i<n; i++)
        {
            dijkstra(i, n, d, G);
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    fout << "0 ";
                else if(d[j]==-1e9)
                    fout << "INF ";
                else
                    fout << -d[j]-h[i]+h[j] << " ";
            }
            fout << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
