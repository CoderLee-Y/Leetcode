//edited on: 2月 08 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int length = arr.size();
        int ans = 1;
        int left = 0, right = 0;
        while (right < length - 1)
        {
            if (left == right)
            {
                if (arr[left] == arr[left + 1])
                    ++left;
                right++;
            }
            else
            {
                if ((arr[right] - arr[right - 1]) * (arr[right + 1] - arr[right]) < 0)
                    ++right;
                else
                    left = right;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};