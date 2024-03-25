// This code is contributed by Riyazul555 and iuliagroza

// Time Complexity  =  O(V + E)  where V is the number of vertices and E is the number of edges.
// Space Complexity =  O(V + E)  where V is the number of vertices and E is the number of edges.
#include <fstream>
#include <vector>
#include <bitset>
#define nMax 100005

using namespace std;

void euler(int nod, vector<pair<int, int>> G[nMax], vector<int>& e, bitset<5*nMax>& viz)
{
    while(!G[nod].empty())
    {
        pair<int, int> it=G[nod].back();
        G[nod].pop_back();
        if(!viz[it.second])
        {
            viz[it.second]=1;
            euler(it.first, G, e, viz);
        }
    }
    e.push_back(nod);
}

int main(int argc, char* argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> G[nMax];
    for(int i=1; i<=m; i++)
    {
        int x, y;
        fin >> x >> y;
        G[x].push_back({y, i});
        G[y].push_back({x, i});
    }
    vector<int> e;
    bitset<5*nMax> viz;
    euler(0, G, e, viz);
    for(int i=e.size()-1; i>0; i--)
        fout << e[i] << ' ';
    return 0;
}