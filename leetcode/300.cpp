#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums;
    //nums = {0,1,0,3,2,3};
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    int l = nums.size();
    int dp[l];
    int i, j, res = 0;
    for (i = 0; i < l; i++)
    {
        dp[i] = 0;
        for (j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (dp[j] > dp[i]) {
                    dp[i] = dp[j];
                }
            }
        }
        dp[i] += 1;
        cout << i << " " << dp[i] << endl;
        if (res < dp[i])
            res = dp[i];
    }

    cout << res << endl;
    return 0;
}