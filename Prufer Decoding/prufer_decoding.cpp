// This code is contributed by Riyazul555 and Iuliagroza

// Time Complexity = O(N)  where N is number of elements in input array 
// Space Complexity = O(N) where N is number of elements in input array

#include <fstream>
#include <vector>
#define nMax 100005

using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, cod[nMax], deg[nMax]={0};
    fin >> n;
    for(int i=0; i<n; i++)
    {
        fin >> cod[i];
        deg[cod[i]]++;
    }
    int ptr=0;
    while(deg[ptr]!=0)
        ptr++;
    int leaf=ptr;
    int p[nMax];
    for(int i=0; i<n; i++)
        p[i]=-1;
    for(int i=0; i<n; i++)
    {
        p[leaf]=cod[i];
        if(--deg[cod[i]]==0 && cod[i]<ptr)
            leaf=cod[i];
        else
        {
            ptr++;
            while(deg[ptr]!=0)
                ptr++;
            leaf=ptr;
        }
    }
    fout << n+1 << "\n";
    for(int i=0; i<n+1; i++)
        fout << p[i] << " ";
    fin.close();
    fout.close();
    return 0;
}