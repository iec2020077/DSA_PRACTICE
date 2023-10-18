//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int x) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int level = 0;

    while (!q.empty()) {
        int nodesAtCurrentLevel = q.size();

        for (int i = 0; i < nodesAtCurrentLevel; i++) {
            int current = q.front();
            q.pop();

            if (current == x) {
                return level;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        level++;
    }

    return -1; // Node x is not found in the graph
}

};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends