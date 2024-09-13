class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> allSubsets;
    int n = nums.size();
    int totalSubsets = 1 << n;  // This is 2^n subsets

    // Iterate over each possible subset (from 0 to 2^n - 1)
    for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) 
    {
        vector<int> currentSubset;

        // Check each bit of subsetMask to decide whether to include nums[i]
        for (int i = 0; i < n; ++i) 
        {
            if (subsetMask & (1 << i)) 
            {
                // If the ith bit is set, include nums[i] in the current subset
                currentSubset.push_back(nums[i]);
            }
        }

        allSubsets.push_back(currentSubset);  // Add current subset to the list
    }

    return allSubsets;
}
};