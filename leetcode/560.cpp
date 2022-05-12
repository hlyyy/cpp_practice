/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int l = nums.size();
        for (int i = 1; i < l; i++)
            nums[i] += nums[i-1];
        if (nums[0] == k)
            res++;
        for (int i = 1; i < l; i++) {
            if (nums[i] == k)
                res++;
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] == k)
                    res++;
            }
        }
        return res;
    }
};
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        map<int, int> m;
        int l = nums.size();
        m[nums[0]] = 1;
        if (nums[0] == k)
            res++;
        for (int i = 1; i < l; i++)
        {
            nums[i] += nums[i - 1];
            if (nums[i] == k)
                res++;
            if (m.find(nums[i] - k) != m.end())
                res += m[nums[i] - k];
            m[nums[i]]++;
            /*
            if (m.find(nums[i]) != m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
            */
        }
        return res;
    }
};