class Solution {
public:
    int count(vector<int>& nums, int subArraySum)
    {
        int n = nums.size();

        int subArray = 1;
        int last = 0;

        for(int i = 0; i < n; i++)
        {
            if(last + nums[i] <= subArraySum)
            {
                last += nums[i];
            }

            else
            {
                subArray++;
                last = nums[i];
            }
        }    
        return subArray;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();

        if(k > n)
            return -1;

        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            sum = sum + nums[i];
        }

        int low = maxi;
        int high = sum;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            int cntSubarray = count(nums, mid);

            if(cntSubarray <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};