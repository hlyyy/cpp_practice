class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int l = nums.size();
        if (l == 1)
            return false;
        int sum = 0;
        for (int i = 0; i < l; i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        int t = sum /2;
        int dp[l][t+1];
        for (int i = 0; i < l; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= t; j++)
            if (nums[0] == j)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        for (int i = 1; i < l; i++) {
            for (int j = 1; j <= t; j++) {
                dp[i][j] = 0;
                if (j-nums[i] >= 0) {
                    if (dp[i-1][j] || dp[i-1][j-nums[i]])
                        dp[i][j] = 1;
                }
                else {
                    if (dp[i-1][j])
                        dp[i][j] = 1;
                }
            }
        }
        if (dp[l-1][t])
            return true;
        return false;
    }
};