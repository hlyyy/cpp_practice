/*
//暴力除法
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        int sum = 1;
        vector<int> v;
        vector<int> res(l,0);
        for (int i = 0; i < l; i++) {
            if (nums[i] == 0)
                v.push_back(i);
            else
                sum *= nums[i];
        }
        if (v.size() == 0) {
            for (int i = 0; i < l; i++) 
                res[i] = int(sum/nums[i]);
        }
        else {
            for (int i = 0; i < l; i++) 
                res[i] = 0;
            int ll = v.size();
            if (ll == 1)
                for (int i = 0; i < v.size(); i++)
                    res[v[i]] = sum;
        }
        return res;
    }
};
*/

//前后缀乘积
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int l = nums.size();
        vector<int> a(l, 0);
        vector<int> b(l, 0);
        vector<int> res(l, 0);
        a[0] = nums[0];
        b[l - 1] = nums[l - 1];
        for (int i = 1; i < l; i++)
            a[i] = a[i - 1] * nums[i];
        for (int i = l - 2; i >= 0; i--)
            b[i] = b[i + 1] * nums[i];
        for (int i = 0; i < l; i++)
            if (i == 0)
                res[i] = b[i + 1];
            else if (i == l - 1)
                res[l - 1] = a[i - 1];
            else
                res[i] = a[i - 1] * b[i + 1];
        return res;
    }
};