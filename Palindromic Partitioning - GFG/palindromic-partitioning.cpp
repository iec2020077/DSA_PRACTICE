//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];
Solution()
{
    memset(dp,-1,sizeof(dp));
}
bool ispalindrome(string s, int i, int j)
{
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        return false;
    }
    return true;
}
int solve(string s, int i, int j)
{
    if(i>=j)
    return 0;
    
    if(ispalindrome(s,i,j))
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    
    int ans=1e9;
    for(int k=i;k<j;k++)
    {
        int temp = 0;
        int left;
        int right;
        
        if(dp[i][k]!=-1)
        left=dp[i][k];
        else
        left=solve(s,i,k);
        
        
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        else
        right=solve(s,k+1,j);
        
        
        temp = 1+ left +  right;
        ans=min(ans,temp);
    }
    
    return dp[i][j]=ans;
}
    int palindromicPartition(string s)
    {
        int n=s.size();
        return solve(s,0,n-1);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends