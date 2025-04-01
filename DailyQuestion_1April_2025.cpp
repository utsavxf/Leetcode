class Solution {
public:

    long long f(int i,int n,vector<vector<int>>&questions,vector<long long>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long pick=questions[i][0]+f(i+questions[i][1]+1,n,questions,dp);
        long long not_pick=f(i+1,n,questions,dp);
        return dp[i]=max(pick,not_pick);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        //typical dp
        int n=questions.size();
        //there is only 1 parameter index i so dp array will be 1d
        // vector<long long>dp(n,-1);
        // return f(0,n,questions,dp);
        
        //let's memoize using copy paste method
        
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
         long long pick = questions[i][0];
         if (i + questions[i][1] + 1 < n) pick+=dp[i + questions[i][1] + 1];
         long long not_pick = dp[i + 1];
         dp[i] = max(pick, not_pick);
         }
        return dp[0];
    }
};
