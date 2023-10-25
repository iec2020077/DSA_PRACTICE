//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
  
//   vector<vector<int>> dp;
  
  int solve(int i, int n, int tar, vector<int> &a,vector<vector<int>> &dp)
  {
      if(tar == 0 and n == i)  // to count all subarray if tar = 0 and arr contain 0 element ass well
      return 1;
      
      if(i == n)
      return 0;
      
      if(dp[i][tar] != -1)
      return dp[i][tar];
      
      if(a[i] <= tar)
      {
          int take = solve(i+1,n,tar - a[i],a,dp);
          int nottake = solve(i+1,n,tar,a,dp);
          
          return dp[i][tar] = (take%mod + nottake%mod)%mod;
      }
      else
      return dp[i][tar] = solve(i+1,n,tar,a,dp)%mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        int tsum = 0;
        for(auto it:arr)
        tsum += it;
        
        int sum = (d + tsum);
        
        if(d > tsum || sum %2 != 0)
        return 0;
        else
        sum /= 2;
        
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        
        return solve(0,n,sum,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends