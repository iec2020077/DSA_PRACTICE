class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int cnt1 =0;
        int cnt2 =0;

        for(int i = 1;i<n-1;i++)
        {
            if(s[i] == s[i-1] and s[i] ==s[i+1] and s[i] =='A')
            cnt1++;
            else if(s[i] == s[i-1] and s[i] ==s[i+1] and s[i] =='B')
            cnt2++;
        }
        if(cnt1 == 0 || cnt2 >= cnt1)return false;
        return true;
        
    }
};