class Solution {
public:
    int rec(int n, vector<int>& memo) {
        if (memo[n] != -1)
            return memo[n];

        if (n == 0)
            return memo[n] = 0;

        if (n == 1)
            return memo[n] = 1;

        if (n % 2 == 0)
            memo[n] = rec(n / 2, memo);
        else
            memo[n] = 1 + rec(n / 2, memo);
        
        return memo[n];
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, -1);  // Initialize memoization array with -1
        
        for (int i = 0; i <= n; i++)
            ans[i] = rec(i, ans);
        
        return ans;
    }
};
