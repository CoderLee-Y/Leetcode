//edited on: 2月 12 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        int a[34][34];
        a[0][0] = 1;
        a[1][0] = a[1][1] = 1;
        for (int i = 2; i <= rowIndex; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                    a[i][j] = 1;
                else
                {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
            }
        }
        vector<int> ret;
        for (int i = 0; i <= rowIndex; ++i)
        {
            ret.push_back(a[rowIndex][i]);
        }
        return ret;
    }
};