//edited on: 11 月 22 日 2020
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int maxSize = 0;
        while (r > l)
        {
            maxSize = max(maxSize, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return maxSize;
    }
};