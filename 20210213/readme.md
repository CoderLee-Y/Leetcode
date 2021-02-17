# 题目
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

**示例:**
输入:
[4,3,2,7,8,2,3,1]
输出:
[5,6]

# 分析
无非就扫描一次，然后输出就行。还是注意vector的用法，vector<int> a(50);的作用就是创建一个大小50的vector，相当于resize一次，对于int类型的会初始化为0.

# 官解
脑经急转弯了，每每遇到一个数字x，就把nums[x-1]+n，这样当我们遇到一个新的就直接nums[nums[i]%n-1]+n即可。这样就可以省下n的空间。