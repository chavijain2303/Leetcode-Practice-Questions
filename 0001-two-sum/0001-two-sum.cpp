class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int idx = 0; idx < n; idx++)
        {
            int a = nums[idx];
            int more = target - a;

            if(mpp.find(more) != mpp.end())
            {
                return {mpp[more], idx};
            }

            mpp[a] = idx;
        }
        return {};
        
    }
};