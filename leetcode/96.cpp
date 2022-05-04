class Solution
{
public:
    int num[20] = {0};
    int numTrees(int n)
    {
        for (int i = 0; i <= n; i++)
            f(i);
        return num[n];
    }
    void f(int n)
    {
        if (n == 0)
        {
            num[n] = 1;
            return;
        }
        if (n == 1)
        {
            num[n] = 1;
            return;
        }
        for (int i = 1; i <= n; i++)
            num[n] += num[n - i] * num[i - 1];
    }
};