//edited on: 2月 11 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> large; //小顶堆

public:
    KthLargest(int ks, vector<int> &nums)
    {
        k = ks;
        if (nums.size() >= k)
        {
            for (int i = 0; i < k; ++i)
                large.push(nums[i]);
            for (int i = k; i < nums.size(); ++i)
                if (nums[i] > large.top())
                {
                    large.pop();
                    large.push(nums[i]);
                }
        }
        else
        {
            for (int i = 0; i < nums.size(); ++i)
                large.push(nums[i]);
        }
    }

    int add(int val)
    {
        if (large.size() < k)
        {
            large.push(val);
        }
        else if (val > large.top())
        {
            large.pop();
            large.push(val);
        }
        return large.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */