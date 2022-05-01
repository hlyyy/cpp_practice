class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int l = s.size();
        if (l == 0)
            return 0;
        int dp[l];
        int res = 0;
        dp[0] = 0;
        for (int i = 1; i < l; i++)
        {
            if (s[i] == '(')
                dp[i] = 0;
            else
            {
                if (s[i - 1] == '(')
                    if (i - 2 >= 0)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                else
                {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0 && dp[i - dp[i - 1] - 2] > 0)
                            dp[i] += dp[i - dp[i - 1] - 2];
                    }
                    else
                        dp[i] = 0;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};