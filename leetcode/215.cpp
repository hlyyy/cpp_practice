class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        return nums[l - k];
    }
};