/*
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> n(nums);
        sort(n.begin(), n.end());
        int l = nums.size();
        int i, j;
        for (i = 0; i < l; i++)
        {
            if (nums[i] != n[i])
                break;
        }
        if (i == l)
            return 0;
        for (j = l - 1; j >= 0; j--)
        {
            if (nums[j] != n[j])
                break;
        }
        return j - i + 1;
    }
};
*/
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int l = nums.size();
        int right = 0, left;
        int max = nums[0];
        int min = nums[l - 1];
        for (int i = 0; i < l; i++)
        {
            if (nums[i] >= max)
                max = nums[i];
            else
                right = i;
        }
        if (right == 0)
            return 0;
        for (int i = l - 1; i >= 0; i--)
        {
            if (nums[i] <= min)
                min = nums[i];
            else
                left = i;
        }
        return right - left + 1;
    }
};