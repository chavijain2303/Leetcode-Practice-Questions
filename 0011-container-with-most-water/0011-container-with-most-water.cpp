class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int maxArea = 0;

        int low = 0; 
        int high = n - 1;

        while(low < high)
        {
            int mini = min(height[low], height[high]);
            int area = (high - low) * mini;
            maxArea = max(maxArea, area);

            if(height[low] < height[high])
                low++;
            
            else
                high--;
        }
        return maxArea;
    }
};