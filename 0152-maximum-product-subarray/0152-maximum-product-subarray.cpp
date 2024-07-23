class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        double maxi = INT_MIN;
        int n = nums.size();

        double prefix = 1, suffix = 1;

        for(int i = 0; i < n; i++)
        {
            if(prefix == 0)
                prefix = 1;

            if(suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];

            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};