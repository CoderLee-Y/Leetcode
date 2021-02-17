//edited on: 2月 05 日 2021
//edited by LEE
#include <bits/stdc++.h>

using namespace std;

class tool
{
private:
    priority_queue<int, vector<int>, less<int>> small; //较小的元素集，应该等于large个数或者多一个
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> hash;
    int k;
    int smallsize, largesize;

    //tools
    void balance()
    {
        if (smallsize > largesize + 1)
        {
            large.push(small.top());
            small.pop();
            --smallsize;
            ++largesize;
            //small top 是久经考验的，不需要重新验证了！
            heapify(small);
        }
        else if (smallsize < largesize)
        {
            small.push(large.top());
            large.pop();
            --largesize;
            ++smallsize;
            heapify(large);
        }
    }

    //弹出m的堆顶元素，更新hash表，注意，改变两个size不在此进行。
    template <typename T>
    void heapify(T &m)
    {
        while (!m.empty())
        {
            int num = m.top();
            if (hash.count(num))
            {
                --hash[num];
                if (hash[num] == 0)
                    hash.erase(num);
                m.pop();
            }
            else
            {
                break;
            }
        }
    }

public:
    tool(int input) : k(input), smallsize(0), largesize(0) {}

    double median()
    {
        if (k % 2 == 1)
            return double(small.top());
        else
            return ((small.top() * 1.0 + large.top()) / 2.0);
    }

    void insert(int num)
    {
        if (small.empty() || num < small.top()) //短路求值防止出错
        {
            small.push(num);
            ++smallsize;
        }
        else
        {
            large.push(num);
            ++largesize;
        }
        balance();
    }

    void erase(int num)
    {
        ++hash[num];
        if (num <= small.top())
        {
            --smallsize;
            if (num == small.top())
                heapify(small);
        }
        else
        {
            --largesize;
            if (num == large.top())
                heapify(large);
        }
        balance();
    }
};

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> a;
        int n = nums.size();
        tool mytool(k);
        for (int i = 0; i < k; ++i)
            mytool.insert(nums[i]);
        a.push_back(mytool.median());
        for (int i = k; i < n; ++i)
        {
            mytool.insert(nums[i]);
            mytool.erase(nums[i - k]);
            a.push_back(mytool.median());
        }
        return a;
    }
};