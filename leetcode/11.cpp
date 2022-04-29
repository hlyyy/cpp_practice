class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = height.size();
        int i = 0, j = l - 1;
        int max_res = min(height[i], height[j]) * (l - 1);
        while (i < j)
        {
            if (height[i] < height[j])
            {
                i += 1;
                max_res = max(max_res, (j - i) * min(height[i], height[j]));
            }
            else
            {
                j -= 1;
                max_res = max(max_res, (j - i) * min(height[i], height[j]));
            }
        }
        return max_res;
    }
};