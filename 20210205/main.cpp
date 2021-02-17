//edited on: 2月 05 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int ans = 0, left = 0, right;
        int length = s.length();
        int currentCost = 0;
        for (right = 0; right < length; ++right)
        {
            currentCost += abs(s[right] - t[right]);

            if (currentCost > maxCost)
            {
                currentCost -= abs(s[left] - t[left]);
                ++left;
            }
        }
        return (right - left);
    }
};