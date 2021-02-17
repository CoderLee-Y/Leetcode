# 题目
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

输入：A = [1,1], B = [2,2]
输出：[1,2]


# 本题主要思路
交换一个糖果，设为AK,BK，则有：AK-BK==(SUMA-SUMB)/2;
我们分为哈希法和双指针法记叙，main函数给出的是哈希法。

# 法一：双指针法
两数组排序，先计算出ANS=(SUMA-SUMB)/2，再用两个指针指向两数组的头，然后计算AK-BK，根据差分为以下三种情况：
AK-BK == ANS,RETURN
AK-BK > ANS,BK右移
AK-BK < ANS,BK左移
这道题返回要求是vector,输入也是vector，我们学习两个vector的常用函数：accumulate求和函数和sort排序函数。指针用int和vector的索引直接替代即可。
accumulate带有三个形参：头两个形参指定要累加的元素范围（迭代器），第三个形参则是累加的初值。其返回类型就是其第三个实参的类型。
可以使用accumulate把string型的vector容器中的元素连接起来：
string sum = accumulate(v.begin() , v.end() , string(" "));

若要求返回简单的vector，可以直接用{x,y}形式，这等价于A[0]=X,A[1]=Y；

# 法二：HASH法
这使用严谨的数学推导来将时间压缩到了ON，上述方法虽然简单易懂但是要求的时间复杂度为ONLOGN，而且完全存在爆int的风险。这体现了算法题中比要数学推导的重要性。
SUMA,SUMB意义一致。设A出X而B出Y，则有：
SUMA-X+Y=SUMB+X-Y
X-Y=(SUMA-SUMB)/2
即我们只需找到这样一对数，A中的X，B中的Y。这采用HASH解决可以将时间复杂度压缩至ON。
### HASH:C++ STL 之 unordered_set 使用
unordered_set::insert
unordered_set::find
unordered_set::erase
1. 这个容器是个集合，所以重复插入相同的值是没有效果的。
2. find的返回值是一个迭代器(iterator)，如果找到了会返回指向目标元素的迭代器，没找到会返回end()。
3. 对于unordered_set，insert/find/erase的平均复杂度是O(1)，但是最坏复杂度是O(N)的。
4. string以及int double之类的基本数据类型，都有默认的哈希函数，而且默认的哈希函数足够好，不会退化到O(N)。
5. 自己写的HASH如果太低效，的确有可能退化到ON.

这里用set就是看准了只需要知道有没有而不需要知道有几个这一特性。


    class Solution {
        public:
            vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
                int sumA = accumulate(A.begin(), A.end(), 0);
                int sumB = accumulate(B.begin(), B.end(), 0);
                int delta = (sumA - sumB) / 2;
                unordered_set<int> rec(A.begin(), A.end());
                vector<int> ans;
                for (auto& y : B) {
                    int x = y + delta;
                    if (rec.count(x)) {
                    ans = vector<int>{x, y};
                    break;
                    }
                }
                return ans;
            }
    };

其中，for (auto& y : B) auto可以自动推测y的类型，：可以遍历B，而&可以使用B中元素的引用。