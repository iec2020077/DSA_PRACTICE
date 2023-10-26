//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
  
//   int dp[1000005];
//   Solution()
//   {
//       memset(dp,-1,sizeof(dp));
//   }
//   int solve(int n)
//   {
//       if(n==0)
//       return 0;
      
//       if(n<0)
//       return 1e9;
      
//       if(dp[n] != -1)
//       return dp[n];
      
//       int a = 1+solve(n-1);
      
//       int b = 1e6;
//       if(n%2 == 0)
//       b = 1+solve(n/2);
      
//       return dp[n] = min(a,b);
//   }
    int minOperation(int n)
    {
        // return solve(n);
        int cnt = 0;
        
        while(n!=0)
        {
            if(n%2 == 0)
            {
                n /= 2;
                cnt++;
            }
            else
            {
                n--;
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends