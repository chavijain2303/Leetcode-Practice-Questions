class Solution {
public:
    // Function to generate subsets (backtracking solution)
    void helper(int idx, vector<int>& current, vector<vector<int>>& ls, vector<int>& nums) 
    {
        ls.push_back(current);  
    
        for (int i = idx; i < nums.size(); i++) 
        {
            current.push_back(nums[i]);
            helper(i + 1, current, ls, nums);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ls;  // To store all subsets
        vector<int> current;     // To store the current subset
        helper(0, current, ls, nums);  // Start recursion
        return ls;  // Return the list of all subsets
    }
};