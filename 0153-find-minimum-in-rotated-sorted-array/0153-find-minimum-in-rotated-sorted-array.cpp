class Solution {
public:
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int mini = nums[0];

    for(int i = 0; i < n; i++)
    {
        if(nums[i] < mini)
            mini = nums[i];
    }
    return mini;
}
};