//edited on: 2月 17 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int a = nums.size(), b = nums[0].size();
        if (r * c != a * b)
            return nums;
        vector<vector<int>> ret(r);
        for (int i = 0; i < r; ++i)
            ret[i].resize(c);
        int e = 0, f = 0;
        for (int i = 0; i < r * c; ++i)
        {
            ret[i / c][i % c] = nums[e][f];
            ++f;
            if (f == b)
            {
                f = 0;
                ++e;
                if (e == a)
                    return ret;
            }
        }
        return ret;
    }
};