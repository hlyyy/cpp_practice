class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = nums.size();
        int i = 0;
        for (int j = 1; j < l - 1; j++)
            if (nums[j] < nums[j - 1])
            {
                i = j;
                break;
            }
        if (i == 0)
        {
            for (int j = 0; j < l; j++)
                if (nums[j] == target)
                    return j;
            return -1;
        }
        if (nums[0] > target)
        {
            if (nums[l - 1] < target)
                return -1;
            for (int j = l - 1; j >= i; j--)
            {
                if (nums[j] == target)
                    return j;
                else if (nums[j] < target)
                    return -1;
            }
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] == target)
                    return j;
                else if (nums[j] > target)
                    return -1;
            }
        }
        return -1;
    }
};