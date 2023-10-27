//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int dp[1001][1001];
  Solution()
  {
      memset(dp,-1,sizeof(dp));
  }
  
  int solve(string s1, string s2, int n, int m)
  {
      if(n == 0 || m == 0)
      return 0;
      
      if(dp[n][m] != -1)
      return dp[n][m];
      
      if(s1[n-1] == s2[m-1])
      return dp[n][m] = 1+solve(s1,s2,n-1,m-1);
      else
      return dp[n][m] = max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
  }
    int minimumNumberOfDeletions(string s) { 
        string t(s.rbegin(),s.rend());
        int n,m;
        n= m = s.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1 ;i <=n ;i++)
        {
            for(int j =1 ;j<= m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] =1+dp[i-1][j-1];
                }
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n - dp[n][m] ;
        // return s.size() - solve(s,t,s.size(),s.size());
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends