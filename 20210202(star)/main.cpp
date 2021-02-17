//edited on: 2月 02 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        int ans = (suma - sumb) / 2;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int i = 0, j = 0;
        while (1)
        {
            if (A[i] - B[j] == ans)
            {
                return {A[i], B[j]};
            }
            if (A[i] - B[j] > ans)
                ++j;
            else
                ++i;
        }
    }
};