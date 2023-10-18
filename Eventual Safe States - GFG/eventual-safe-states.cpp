//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int vertex,vector<int> graph[],bool vis[],bool dfsvis[],bool check[])
{
    vis[vertex]=true;
    dfsvis[vertex]=true;
    
    check[vertex]=false;

    for(auto child:graph[vertex])
    {
        if(!vis[child])
        {
         if(dfs(child,graph,vis,dfsvis,check)) 
           return true;
        }
        else if(dfsvis[child])
         return true;
    }
    check[vertex]=true;
    dfsvis[vertex]=false;   
    return false;
}

    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        // code here
        // vector<int > ans;
       vector<int > ans;
        bool vis[n];
        for(int i=0;i<n;i++)
        vis[i]=false;
        bool dfsvis[n];
        for(int i=0;i<n;i++)
        dfsvis[i]=false;
        bool check[n];
        for(int i=0;i<n;i++)
        check[i]=false;

        for(int i=0;i<n;i++)
        {
              if(!vis[i])
              {
                  dfs(i,graph,vis,dfsvis,check);
              }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==true) ans.push_back(i);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends