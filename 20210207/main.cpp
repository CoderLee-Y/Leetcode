//edited on: 2月 07 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] >= nums[i])
                continue;
            if (i - 1 >= 0 && nums[i - 1] > nums[i + 1] && i + 2 < nums.size() && nums[i + 2] < nums[i])
                return false;
            if (!flag)
            {
                flag = true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};