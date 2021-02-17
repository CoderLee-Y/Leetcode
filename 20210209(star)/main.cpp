//edited on: 2月 09 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return (getMostK(A, K) - getMostK(A, K - 1));
    }

    int getMostK(vector<int> &A, int K)
    {
        int ans = 0, left = 0, right = 0;
        int n = A.size();
        unordered_map<int, int> hash;
        for (; right < n; ++right)
        {
            hash[A[right]]++;
            while (hash.size() > K)
            {
                if (--hash[A[left]] == 0)
                    hash.erase(A[left]);
                ++left;
            }
            ans += (right - left);
        }
        return ans;
    }
};