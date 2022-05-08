class Solution
{
public:
    vector<vector<int>> res;
    vector<int> c;
    vector<int> r;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        c.swap(candidates);
        dfs(target, 0);
        return res;
    }
    void dfs(int t, int begin)
    {
        if (t == 0)
        {
            res.push_back(r);
            return;
        }
        else if (t < 0)
            return;
        for (int i = begin; i < c.size(); i++)
        {
            r.push_back(c[i]);
            dfs(t - c[i], i);
            r.pop_back();
        }
    }
};