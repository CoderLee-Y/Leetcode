//edited on: 2月 05 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, right, temp;
        double ans = 0;
        for (int i = 0; i < k; ++i)
            sum += nums[i];
        temp = sum;
        for (int i = k; i < n; ++i)
        {
            temp = temp + nums[i] - nums[i - k];
            if (temp > sum)
                sum = temp;
        }
        ans = sum;
        return (ans / k);
    }
};