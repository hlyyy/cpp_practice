class Solution
{
public:
    int countSubstrings(string s)
    {
        int l = s.size();
        int dp[l][l];
        int i, j, res = 0;
        for (i = l - 1; i >= 0; i--)
        {
            for (j = i; j < l; j++)
            {
                if (i == j)
                    dp[i][i] = 1;
                else if (j - i == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (dp[i + 1][j - 1] == 1 && s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};