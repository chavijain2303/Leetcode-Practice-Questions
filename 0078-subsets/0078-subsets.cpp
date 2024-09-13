class Solution {
public:
    void helper(int idx, vector<int>& current, vector<vector<int>>& ls, vector<int>& nums, int n) 
    {
        if (idx >= n) 
        {
            ls.push_back(current);  // Add the current subset to the list of subsets
            return;
        }

        // Include nums[idx] in the current subset
        current.push_back(nums[idx]);
        helper(idx + 1, current, ls, nums, n);  // Explore with current element

        // Exclude nums[idx] from the current subset
        current.pop_back();
        helper(idx + 1, current, ls, nums, n);  // Explore without current element
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ls;  // To store all subsets

        vector<int> current;  // To store the current subset

        int n = nums.size();

        helper(0, current, ls, nums, n);  // Call the helper function
        
        return ls;  // Return the list of all subsets
    }

};