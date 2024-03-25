// This code is contributed by Riyazul555 and iuliagroza

// Time Complexity = O(N*(N+M))   N represents the number of vertices in the graph.
// Space Complexity = O(N+M)      M represents the number of edges in the graph.

#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define nMax 25

using namespace std;

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
    bool more_colors=1;
    int solk=0, colk[nMax]={0};
    for(int k=1; k<=n && more_colors; k++)
    {
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
                if(col[j]>=0)
                    ap[col[j]]=1;
            int ncol=0;
            while(ap[ncol] && ncol<k)
                ncol++;
            if(ncol<k)
                col[st[i]]=ncol;
            else
                col[st[i]]=-2;
        }
        bool ok=1;
        int Max=-1;
        for(int i=0; i<n && ok; i++)
        {
            if(col[i]<0)
                ok=0;
            Max=max(Max, col[i]);
        }
        if(ok)
        {
            solk=Max+1;
            for(int i=0; i<n; i++)
                colk[i]=col[i];
            more_colors=0;
        }
    }
    fout << solk << '\n';
    for(int i=0; i<n; i++)
        fout << colk[i] << ' ';
    fin.close();
    fout.close();
    return 0;
}