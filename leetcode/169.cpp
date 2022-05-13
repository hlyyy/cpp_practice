class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int l = nums.size();
        map<int, int> m;
        for (int i = 0; i < l; i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > l / 2.0)
                return nums[i];
        }
        return 0;
    }
};