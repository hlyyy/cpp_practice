class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] > b[0])
            return true;
        else if (a[0] == b[0])
            return a[1] < b[1];
        else
            return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int l = people.size();
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        res.push_back(people[0]);
        for (int i = 1; i < l; i++)
            res.insert(res.begin() + people[i][1], people[i]);
        return res;
    }
};