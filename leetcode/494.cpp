class Solution
{
public:
    int res = 0, sum = 0;
    int l, t;
    vector<int> v;
    int findTargetSumWays(vector<int> &nums, int target)
    {
        l = nums.size();
        t = target;
        v.swap(nums);
        dfs(0);
        return res;
    }
    void dfs(int i)
    {
        if (i == l)
        {
            if (sum == t)
                res++;
            return;
        }
        sum += v[i];
        dfs(i + 1);
        sum -= 2 * v[i];
        dfs(i + 1);
        sum += v[i];
    }
};