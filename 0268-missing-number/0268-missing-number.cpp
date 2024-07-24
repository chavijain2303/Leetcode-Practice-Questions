class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();

        // Initialize variable to store the XOR result
        int xor_result = 0;

        // Iterate through numbers from 0 to n and elements in the array
        for(int i = 0; i <= n; i++) 
        {
            // XOR the current number from 0 to n
            xor_result = xor_result ^ i;

            // XOR the current element if within the array bounds
            if (i < n)
                xor_result = xor_result ^ nums[i];
        }

        // The remaining value is the missing number
        return xor_result;
    }
};