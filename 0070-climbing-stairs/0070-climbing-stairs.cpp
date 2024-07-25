class Solution {
public:

    int memo(int n, vector<int>&dp)
    {
        if(n == 1)
            return 1;
        
        if(n == 0)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int left = memo(n - 1, dp);
        int right = memo(n - 2, dp);

        dp[n] = left + right;

        return dp[n];
    }

    int climbStairs(int n) 
    {
        //memo
        vector<int>dp(n + 1, -1);
        return memo(n, dp);
    }
};