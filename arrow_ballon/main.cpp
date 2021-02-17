//edited on: 11 月 23 日 2020
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    struct point
    {
        vector<int> pointer;
        bool stepped;
        point() : stepped(false) {}
    };

    static bool cmp(point x1, point x2)
    {
        return (x1.pointer[1] < x2.pointer[1]);
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        point *p;
        int ans = 0;
        p = new point[points.size()];
        for (int i = 0; i < points.size(); ++i)
        {
            p[i].pointer = points[i];
        }
        sort(p, p + points.size(), cmp);
        for (int i = 0; i < points.size(); ++i)
        {
            if (p[i].stepped)
                continue;
            ++ans;
            for (int j = i; j < points.size(); ++j)

            {
                if (p[j].stepped)
                    continue;
                if (p[j].pointer[0] > p[i].pointer[1])
                    continue;
                if (p[j].pointer[0] <= p[i].pointer[1])
                {
                    p[j].stepped = true;
                }
            }
        }
        return ans;
    }
};