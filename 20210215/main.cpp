//edited on: 2月 15 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int left = 0, right = 0, n = nums.size(), ret = 0;
        while (right < n)
        {
            if (nums[right])
            {
                ++right;
                ret = max(ret, right - left);
            }
            else
            {
                left = (++right);
            }
        }
        return ret;
    }
};