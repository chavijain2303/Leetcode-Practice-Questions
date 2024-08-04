class Solution {
public:

    bool poss(vector<int>& bloomDay, int m, int k, int day)
    {
        int n = bloomDay.size();
        int cnt = 0; 
        int totBouq = 0;

        for(int i = 0; i < n; i++)
        {
            if(bloomDay[i] <= day)
                cnt++;
            
            else
            {
                totBouq += (cnt / k);
                cnt = 0;
            }
        }

        totBouq += (cnt / k);

        if(totBouq >= m)
            return true;
        
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int val = m * 1LL * k * 1LL;
        if(n < val)
            return -1;
        
        int low = mini;
        int high = maxi;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(poss(bloomDay, m, k, mid) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};