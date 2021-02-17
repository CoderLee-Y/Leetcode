# 题目
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。
示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])
示例 2：

输入：[4,8,12,16]
输出：2

# 面向示例编程：runtime error.
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int beg = 0, a = 0, length = arr.size();
        int current, past;
        int maxe = 1;
        for (int i = 1; i < length; ++i)
        {
            current = arr[i] - arr[a];
            if (i == 1)
                past = -current;
            if (current * past < 0)
            {
                ++a;
                past = current;
                maxe = max(maxe, i - beg + 1);
            }
            else
            {
                maxe = max(maxe, i - beg);
                beg = a;
                past = arr[i] - arr[a];
                a = i;
                if (past == 0)
                    ++beg
            }
        }
        return maxe;
    }
};

# 双指针法
长度设为n,设有一个区间[left,right]存在。里面**已经**有一个目标数组。那么接下来我们只需要考虑：
1. right right-1 right+1 (假设right<length - 1) 满足湍流数组的关系，那么直接右移right即可。
2. 若不满足，则left=right继续前进。

关键是要考虑长度为1的特殊情况。只有一种情况必须left right同时右移，即a[right]==a[right+1].

**必须指出，你的初始想法是正确的，也是双指针法，但是你的写码能力有点差，所以面向错误编程了非常多次。这对我们是一个惊醒。**

**上述错误代码的最终问题是堆湍流判断的省事儿导致的爆int.**

