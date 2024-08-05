class Solution {
public:
    int calc(vector<int>&weight, int capacity)
    {
        int n = weight.size();
        int days = 1;
        int load = 0;

        for(int i = 0; i < n; i++)
        {
            if(load + weight[i] > capacity)
            {
                days++;
                load = weight[i];
            }
            else
                load += weight[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weight, int days) 
    {
        int n = weight.size();

        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i< n; i++)
        {
            maxi = max(maxi, weight[i]);
            sum = sum + weight[i];
        }

        int low = maxi;
        int high = sum;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int daysReq = calc(weight, mid);

            if(daysReq <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};