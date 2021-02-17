//edited on: 11 月 22 日 2020
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int m = candidates.size() - 1;
        while(candidates[m]>target)--m;
        candidates[m+1]=target;
        
    }
};