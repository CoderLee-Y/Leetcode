//edited on: 2月 02 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxOfChar = 0, left = 0, a[26];
        memset(a, 0, sizeof(a));
        for (int right = 0; right < s.size(); ++right)
        {
            int current = s[right] - 'A';
            ++a[current];
            maxOfChar = max(maxOfChar, a[current]);
            if (right - left + 1 > maxOfChar + k)
            {
                --a[left];
                ++left;
            }
        }
        return (s.size() - left);
    }
};