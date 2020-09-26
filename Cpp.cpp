#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i, int father, int f[], vector<vector<int>> &s, int length[], int &a)
{
    /* i = dfs is running from this node
    father = the node from which we have come to node i
    f[] = the array which contains father of each node
    s = adjacency list of the graph
    length[] = it contains the length of path from each node to the node from which we have started depth-first-search
    a = the node which has the longest distance from the node we have started depth-first-search
    */
    length[i] = length[father] + 1;
    f[i] = father;
    if (length[i] > length[a])
        a = i;
    for (int v : s[i])
    {
        if (v != father)
        {
            dfs(v, i, f, s, length, a);
        }
    }
}

void printpath(int i, int father[])
{
    // i = last node in the longest path
    // father[] = father of i-th node is in index i
    do
    {
        cout << i << " ";
        i = father[i];
    } while (i);
}

void diameter(int n, vector<vector<int>> &s, int father[])
{
    int lenght[n + 1] = {-1};
    int a = 1;
    // finding the start of diameter
    dfs(1, 0, father, s, lenght, a);
    int b = 1;
    // finding end of diameter
    dfs(a, 0, father, s, lenght, b);
    // printing diameter
    printpath(b, father);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> s(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a].push_back(b);
        s[b].push_back(a);
    }
    int father[n + 1];
    diameter(n, s, father);
}
