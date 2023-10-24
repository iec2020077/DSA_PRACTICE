//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1003][1004];
Solution()
{
    memset(dp,-1,sizeof(dp));
}
int solve(int n, int tar, int i, int val[], int wt[])
{
    if(i == n || tar == 0)
    return 0;
    
    if(dp[i][tar] != -1)
    return dp[i][tar];
    
    if(wt[i] <= tar)
    {
        return dp[i][tar] = max(val[i] + solve(n,tar-wt[i],i,val,wt),0 + solve(n,tar,i+1,val,wt));
    }
    else
    return dp[i][tar] = solve(n,tar,i+1,val,wt);
    
}
    int knapSack(int n, int W, int val[], int wt[])
    {
        return solve(n,W,0,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends