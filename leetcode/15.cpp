class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int l = nums.size();
        int i, j, k;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> re;
        if (l < 3)
            return res;
        else if (nums[0] > 0)
            return res;
        else
        {
            for (i = 0; i < l; i++)
            {
                if (nums[i] > 0)
                    break;
                for (j = i + 1, k = l - 1; j < k;)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> r(3, 0);
                        r[0] = nums[i];
                        r[1] = nums[j];
                        r[2] = nums[k];
                        res.push_back(r);
                        j++;
                        k--;
                        while (j < k && nums[j + 1] == nums[j] && nums[j] != (-1) * nums[i] / 2)
                            j++;
                        while (j < k && nums[k - 1] == nums[k] && nums[k] != (-1) * nums[i] / 2)
                            k--;
                    }
                    else if (nums[i] + nums[j] + nums[k] < 0)
                    {
                        j++;
                        while (j < k && nums[j + 1] == nums[j] && nums[j] != (-1) * nums[i] / 2)
                            j++;
                    }
                    else
                    {
                        k--;
                        while (j < k && nums[k - 1] == nums[k] && nums[k] != (-1) * nums[i] / 2)
                            k--;
                    }
                }
            }
            set<vector<int>> re(res.begin(), res.end());
            res.assign(re.begin(), re.end());
            return res;
        }
    }
};