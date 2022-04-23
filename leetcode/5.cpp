#include<iostream>
using namespace std;

/*
string longestPalindrome(string s)
{
    int a, b, flag;
    string res;
    int l = s.size();
    for (int i = 0; i < l; i++)
    {
        for (int j = l - 1; j > i; j--)
        {
            if (s[i] != s[j])
                continue;
            else
            {
                flag = 0;
                for (a = i, b = j; a != b && a-b != 1; a++, b--)
                {
                    if (s[a] != s[b])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    if (j - i + 1 > res.size())
                        res = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return res;
}
*/

string longestPalindrome(string s)
{
    int l = s.size();
    int dp[l][l];
    int i, j, max_i, max_j, max_len = 1;
    for (i = l - 1; i >= 0; i--)
    {
        for (j = i; j < l; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (j - i == 1)
            {
                if (s[i] == s[j]) {
                    dp[i][j] = 1;
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        max_i = i;
                        max_j = j;
                    }
                }
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        max_i = i;
                        max_j = j;
                    }
                }
                else
                    dp[i][j] = 0;
            }
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    if (max_len == 1)
        return s.substr(0, 1);
    return s.substr(max_i, max_j - max_i + 1);
}

int main() {
    cout << longestPalindrome("abcd") << endl;
    return 0;
}