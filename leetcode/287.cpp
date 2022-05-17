class Solution
{
public:
    //快慢指针
    int findDuplicate(vector<int> &nums)
    {
        int fast = 0, slow = 0, find = 0;
        while (1)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if (slow == fast)
                break;
        }
        while (1)
        {
            find = nums[find];
            slow = nums[slow];
            if (slow == find)
                break;
        }
        return slow;
    }
};