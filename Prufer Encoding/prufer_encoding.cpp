// This code is contributed by Riyazul555 and Iuliagroza

// Time Complexity  =  O(N)  N is number of nodes in the tree
// Space Complexity = O(N)  N is number of nodes in the tree

#include <fstream>
#include <vector>
#define nMax 100005

using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, daddy[nMax], deg[nMax]={0};
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> daddy[i];
        deg[i]++;
        deg[daddy[i]]++;
    }
    int ptr=-1;
    for(int i=0; i<n; i++)
        if(deg[i]==1 && ptr==-1)
            ptr=i;
    vector<int> sol;
    int leaf=ptr;
    for(int i=0; i<n-1; i++)
    {
        int nxt=daddy[leaf];
        sol.push_back(nxt);
        if(--deg[nxt]==1 && nxt<ptr)
            leaf=nxt;
        else
        {
            ptr++;
            while(deg[ptr]!=1)
                ptr++;
            leaf=ptr;
        }
    }
    fout << n-1 << "\n";
    for(auto i:sol)
        fout << i << " ";
    fin.close();
    fout.close();
    return 0;
}