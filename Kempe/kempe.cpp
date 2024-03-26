//This code was contributed by Riyazul555 and Iuliagroza

//Time Complexity = O(2^N), where N is the number of vertices
//Space Complexity = O(N + M), where M is the number of edges

#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define nMax 25

using namespace std;

const int MOD = 1077563119;

void bfs(int nod, vector<int> G[nMax], bool viz[nMax])
{
    queue<int> Q;
    viz[nod]=1;
    Q.push(nod);
    while(!Q.empty())
    {
        nod=Q.front();
        Q.pop();
        for(auto i:G[nod])
            if(!viz[i])
        {
            viz[i]=1;
            Q.push(i);
        }
    }
}

bool isConnected(int n, int m, vector<int> G[nMax], vector<int> vert)
{
    bool viz[nMax]={0};
    bfs(vert[0], G, viz);
    for(auto i:vert)
        if(!viz[i])
            return 0;
    return 1;
}

bool isComplete(int n, vector<int> G[nMax], vector<int> vert)
{
    for(auto i:vert)
        if(G[i].size()!=n-1)
            return 0;
    return 1;
}

long long chromaticPolynomial(int k, int n, int m, vector<int> G[nMax], vector<int> vert)
{
    if(m==0)
    {
       long long p=1;
       for(int i=1; i<=n; i++)
            p=(p%MOD*k%MOD)%MOD;
       return p;
    }
    if(isComplete(n, G, vert))
    {
        long long p=1;
        for(int i=k-n+1; i<=k; i++)
            p=(p%MOD*i%MOD)%MOD;
        return p;
    }
    if(isConnected(n, m, G, vert) && m==n-1)
    {
        long long p=k%MOD;
        for(int i=1; i<n; i++)
            p=(p%MOD*(k-1)%MOD)%MOD;
        return p;
    }
    vector<int> G1[nMax];
    int ind=0;
    while(G[vert[ind]].size()==0)
        ind++;
    int p1=vert[ind];
    int p2=G[p1].back();
    for(auto i:vert)
        for(auto j:G[i])
        {
            if((i==p1 && j==p2) || (i==p2 && j==p1))
                continue;
            G1[i].push_back(j);
        }
    vector<int> vert2;
    for(auto i:vert)
        if(i!=p2)
            vert2.push_back(i);
    vector<int> G2[nMax];
    for(auto i:vert2)
    {
        for(auto j:G1[i])
            if(j==p2)
            {
                if(find(G2[i].begin(), G2[i].end(), p1)==G2[i].end())
                    G2[i].push_back(p1);
            }
            else
            {
                if(find(G2[i].begin(), G2[i].end(), j)==G2[i].end())
                    G2[i].push_back(j);
            }
        if(i==p1)
            for(auto j:G1[p2])
                if(find(G2[i].begin(), G2[i].end(), j)==G2[i].end())
                    G2[i].push_back(j);
    }
    int sz=0;
    for(auto i:vert2)
    {
        sz+=G2[i].size();
    }
    sz/=2;
    return (chromaticPolynomial(k, n, m-1, G1, vert)%MOD-chromaticPolynomial(k, n-1, sz, G2, vert2)%MOD+MOD)%MOD;
}

int chromaticNumber(int n, int m, vector<int> G[nMax], vector<int> vert)
{
    for(int i=1; i<=n; i++)
        if(chromaticPolynomial(i, n, m, G, vert))
            return i;
}

int main(int argc, char* argv[])
{
    ifstream fin("pc.in");
    ofstream fout("pc.out");
    int n, m;
    fin >> n >> m;
    vector<int> G[nMax];
    for(int i=1; i<=m; i++)
    {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> vert;
    for(int i=0; i<n; i++)
        vert.push_back(i);
    int k = chromaticNumber(n, m, G, vert);
    fout << k << '\n';
    int st_sz=0, st[nMax]={0}, gr[nMax]={0};
    for(int i=0; i<n; i++)
        gr[i]=G[i].size();
    while(st_sz<n)
    {
        int cnt=0;
        for(int i=0; i<n; i++)
            if(gr[i]>-1 && gr[i]<k)
        {
            gr[i]=-1;
            st[st_sz++]=i;
            for(auto j:G[i])
                gr[j]--;
            cnt++;
        }
        if(cnt==0)
        {
            int pos=0;
            while(gr[pos]==-1 && pos<n-1)
                pos++;
            gr[pos]=-1;
            st[st_sz++]=pos;
            for(auto j:G[pos])
                gr[j]--;
        }
    }
    int col[nMax];
    fill(col, col+20, -1);
    for(int i=st_sz-1; i>=0; i--)
    {
        bool ap[k]={0};
        for(auto j:G[st[i]])
            if(col[j]!=-1)
                ap[col[j]]=1;
        int ncol=0;
        while(ap[ncol] && ncol<k)
            ncol++;
        if(ncol<k)
            col[st[i]]=ncol;
    }
    for(int i=0; i<n; i++)
        fout << col[i] << ' ';
    fin.close();
    fout.close();
    return 0;
}