class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 0)
            return 0;
        int dp[l];
        int max_res = 1;
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < l; i++)
        {
            if (nums[i] - nums[i - 1] == 1)
                dp[i] = dp[i - 1] + 1;
            else if (nums[i] == nums[i - 1])
                dp[i] = dp[i - 1];
            else
                dp[i] = 1;
            max_res = max(max_res, dp[i]);
        }
        return max_res;
    }
};