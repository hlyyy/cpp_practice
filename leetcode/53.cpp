class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN;
        int sum;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
        {
            sum = 0;
            for (vector<int>::iterator j = i; j != nums.end(); j++)
            {
                sum += *j;
                if (sum > max)
                {
                    max = sum;
                }
            }
        }
        return max;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int i = nums.size();
        vector<int> dp(i, 0);
        for (int j = 0; j < i; j++)
        {
            if (j == 0)
            {
                dp[0] = nums[0];
            }
            else
            {
                if (dp[j - 1] > 0)
                    dp[j] = dp[j - 1] + nums[j];
                else
                    dp[j] = nums[j];
            }
            res = max(res, dp[j]);
        }
        return res;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int i = nums.size();
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            if (sum > 0)
                sum += nums[j];
            else
                sum = nums[j];
            res = max(res, sum);
        }
        return res;
    }
};
