class Solution
{
public:
    vector<vector<int>> v;
    vector<int> vv;
    int chosen[7];
    vector<vector<int>> permute(vector<int> &nums)
    {
        int l = nums.size();
        c(1, l, nums);
        return v;
    }
    void c(int i, int l, vector<int> &nums)
    {
        if (i == l + 1)
        {
            v.push_back(vv);
            return;
        }
        for (int j = 0; j < l; j++)
        {
            if (!chosen[j])
            {
                chosen[j] = 1;
                vv.push_back(nums[j]);
                c(i + 1, l, nums);
                chosen[j] = 0;
                vv.pop_back();
            }
        }
    }
};