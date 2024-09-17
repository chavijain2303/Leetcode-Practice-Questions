class Solution {
public:
    void helper(int idx, int target, int n, vector<int>&nums, vector<int>&ls, vector<vector<int>>&res)
    {
        if(idx == n)
        {
            if(target == 0)
                res.push_back(ls);

            return;
        }

        if(nums[idx] <= target)
        {
            ls.push_back(nums[idx]);

            helper(idx, target - nums[idx], n, nums, ls, res);

            ls.pop_back();
        }

        helper(idx + 1, target, n, nums, ls, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>res;
        vector<int>ls;
        int n = candidates.size();
        helper(0, target, n, candidates, ls, res);
        return res;
        
    }
};