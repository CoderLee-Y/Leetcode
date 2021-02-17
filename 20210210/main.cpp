//edited on: 2月 10 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size(), len2 = s2.size();
        int left = 0, right = 0;
        unordered_map<char, int> a;
        for (int i = 0; i < len1; ++i)
            ++a[s1[i]];
        while (right < len2)
        {
            if (a.count(s2[right]) > 0 && a[s2[right]] > 0)
            {
                --a[s2[right]];
                ++right;
                if (right - left == len1)
                    return true;
            }
            else
            {
                while ((a.count(s2[right]) <= 0 || a[s2[right]] == 0) && right >= left)
                {
                    if (left == right)
                    {
                        ++left;
                        ++right;
                        break;
                    }
                    else
                    {
                        ++a[s2[left]];
                        ++left;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution a;
    if (a.checkInclusion("hello", "ooolleoooleh"))
        cout << "true";
    else
        cout << "false";
}