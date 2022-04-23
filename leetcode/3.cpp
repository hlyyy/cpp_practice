class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = s.size();
        set<char> se;
        int i, j, max_l = 0;
        for (j = 0; j < l; j++)
        {
            if (se.count(s[j]) == 0)
                se.insert(s[j]);
            else
                break;
        }
        max_l = se.size();
        for (i = 0; i < l; i++)
        {
            se.erase(s[i]);
            for (; j < l; j++)
            {
                if (se.count(s[j]) == 0)
                    se.insert(s[j]);
                else
                    break;
            }
            if (se.size() > max_l)
                max_l = se.size();
        }
        return max_l;
    }
};