# 题目
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

*示例1:*
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba")

*示例2:*
输入: s1= "ab" s2 = "eidboaoo"
输出: False

# 分析
差点没被气死...一定要切实提高看英文文档的能力。在cpp reference种明确指出了，count()的功能是有返回0以上的，而不是直接给出值的大小！！unordered_map还是要仔细学学怎么用。
用时1h25min medium 
执行用时28 ms, 在所有 C++ 提交中击败了58.86%的用户
内存消耗：7.3 M, 在所有 C++ 提交中击败了82.96%的用户