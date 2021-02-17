//edited on: 2月 06 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int num = cardPoints.size();
        int temp, sum = 0;
        for (int i = 0; i < k; ++i)
            sum += cardPoints[i];
        temp = sum;
        for (int j = num - 1; j >= 0 && k + j - num >= 0; --j)
        {
            temp = temp + cardPoints[j] - cardPoints[k + j - num];
            if (temp > sum)
                sum = temp;
        }
        return sum;
    }
};