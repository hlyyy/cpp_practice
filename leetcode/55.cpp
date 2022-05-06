class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int l = nums.size();
        int max_l = 0;
        for (int i = 0; i < l; i++)
        {
            if (i <= max_l)
                max_l = max(i + nums[i], max_l);
            else
                return false;
            if (max_l >= l - 1)
                return true;
        }
        return false;
    }
};