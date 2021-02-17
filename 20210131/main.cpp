//edited on: 1月 31 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> a;

    int find(int x)
    {
        if (a[x] == x)
            return x;
        return (a[x] = find(a[x]));
    }

    bool check(const string &x, const string &y, int length)
    {
        int num = 0;
        for (int i = 0; i < length; ++i)
            if (x[i] != y[i])
                ++num;
        if (num == 0 || num == 2)
            return true;
        return false;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].length();
        a.resize(n);
        for (int i = 0; i < n; ++i)
            a[i] = i;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int x = find(i), y = find(j);
                if (x == y)
                    continue;
                if (check(strs[i], strs[j], m))
                {
                    a[x] = y;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == i)
                ++ret;
        return ret;
    }
};

//last edited by LEE
//the latest editing date:
//14 44 55 (HHMMSS)
//1月 31 日 2021
//AC