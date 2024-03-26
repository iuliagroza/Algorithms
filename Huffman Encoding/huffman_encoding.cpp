// This code is contributed by Riyazul555 and Iuliagroza

// Time complexity  = O(N log N)   N is number of unique characters
// Space complexity = O(N)         N is number of unique characters

#include <fstream>
#include <queue>
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
    map<char, int> ap;
    string s;
    vector<char> v;
    int val[nMax]={0};
    getline(fin, s);
    for(int i=0; i<s.size(); i++)
    {
        ap[s[i]]++;
        if(find(v.begin(), v.end(), s[i])==v.end())
            v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    int fr[nMax]={0};
    int n=v.size();
    fout << v.size() << "\n";
    for(int i=0; i<n; i++)
    {
        fout << v[i] << " " << ap[v[i]] << "\n";
        fr[i]=ap[v[i]];
        val[i]=i;
    }
    auto compare = [&fr, &val](int a, int b) { return ((fr[a] > fr[b])  || (fr[a]==fr[b] && val[a]>val[b]));};
    priority_queue<int, vector<int>, decltype(compare)> Q(compare);
    for(int i=0; i<n; i++)
        Q.push(i);
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
    map<char, string> codif;
    for(int i=0; i<n; i++)
        codif[v[i]]=cod[i];
    for(int i=0; i<s.size(); i++)
        fout << codif[s[i]];
    fin.close();
    fout.close();
    return 0;
}