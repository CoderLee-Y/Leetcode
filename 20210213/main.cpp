//edited on: 2月 13 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
            ++ret[nums[i] - 1];
        int cap = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ret[i] == 0)
                ret[cap++] = i + 1;
        }
        ret.resize(cap);
        return ret;
    }
};