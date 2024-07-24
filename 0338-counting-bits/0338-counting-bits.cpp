class Solution {
public:
    int rec(int n)
    {
        if(n == 0)
            return 0;

        if(n == 1)
            return 1;

        if(n % 2 == 0)
            return rec(n / 2);
        else
            return (1 + rec(n/2));
    }

    vector<int> countBits(int n) 
    {
        vector<int> ans(n + 1);
        
        for(int i = 0; i <= n; i++)
            ans[i] = rec(i);
        
        return ans;
    }
};