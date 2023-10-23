//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1005][1005];
	Solution()
	{
	    memset(dp,-1,sizeof(dp));
	}
	int solve(int arr[], int n, int i, int prev)
	{
	    if(i==n)
	    return 0;
	    
	    
	    if(dp[i][prev+1]!=-1)
	    return dp[i][prev+1];
	    
	    int take=0;
	    int nottake=0;
	    if(prev==-1 || arr[prev]<arr[i])
	    {
	        take=arr[i]+solve(arr,n,i+1,i);
	        nottake=solve(arr,n,i+1,prev);
	    }
	    else
	    nottake=solve(arr,n,i+1,prev);
	    
	    return dp[i][prev+1]=max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    return solve(arr,n,0,-1);
	}  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends