// This code is contributed by Riyazul555 and Iuliagroza

// Time Complexity: O(N log N)  N is the size of the input file
// Space Complexity: O(N)       N is the size of the input file

#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define nMax 20005

using namespace std;

void dfs(int nod, string val, int G[nMax][2], string cod[nMax])
{
    if(G[nod][0]==-1)
    {
        cod[nod]=val;
        return;
    }
    dfs(G[nod][0], val+"0", G, cod);
    dfs(G[nod][1], val+"1", G, cod);
}

int main(int argc, char* argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, fr[nMax], val[nMax];
    fin >> n;
    fin.get();
    vector<char> v;
    auto compare = [&fr, &val](int a, int b) { return ((fr[a] > fr[b])  || (fr[a]==fr[b] && val[a]>val[b]));};
    priority_queue<int, vector<int>, decltype(compare)> Q(compare);
    for(int i=0; i<n; i++)
    {
        char ch;
        fin.get(ch);
        v.push_back(ch);
        fin >> fr[i];
        val[i]=i;
        Q.push(i);
        fin.get();
    }
    int G[nMax][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<nMax; j++)
            G[j][i]=-1;
    int z=n-1;
    while(Q.size()>1)
    {
        int x=Q.top();
        Q.pop();
        int y=Q.top();
        Q.pop();
        z++;
        fr[z]=fr[x]+fr[y];
        val[z]=min(val[x], val[y]);
        Q.push(z);
        G[z][0]=x;
        G[z][1]=y;
    }
    string cod[nMax]={""};
    dfs(z, "", G, cod);
    string s1, s2="";
    getline(fin, s1);
    for(int i=0; i<s1.size(); i++)
    {
        s2+=s1[i];
        bool ok=0;
        for(int j=0; j<v.size() && !ok; j++)
            if(s2 == cod[j])
            {
                fout << v[j];
                s2="";
                ok=1;
            }
    }
    return 0;
}