class Solution {
public:
    int largest(vector<int>&arr)
    {
        int n = arr.size();
        int maxi = arr[0];

        for(int i = 0; i < n; i++)
        {
            if(arr[i] > maxi)
                maxi = arr[i];
        }
        return maxi;
    }

    int func(vector<int>& arr, int speed) 
    {
        int totHrs = 0;

        for (int i = 0; i < arr.size(); i++) 
        {
            // Equivalent to ceil(arr[i] / (double)speed)
            totHrs += (arr[i] + speed - 1) / speed; 
        }
        return totHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1, high = largest(piles);

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            int totHrs = func(piles, mid);

            if(totHrs <= h)
            {
                high = mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};