# 题目
N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。

人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)。

这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。

**示例 1:**
输入: row = [0, 2, 1, 3]
输出: 1
解释: 我们只需要交换row[1]和row[2]的位置即可。
**示例 2:**
输入: row = [3, 2, 0, 1]
输出: 0
解释: 无需交换座位，所有的情侣都已经可以手牵手了。

# 分析
首先，是“最少”。思考一下，人的总数减少一次，是不是必定会有所有情侣均成功牵手的结果出现？

**仔细思考，我们把牵手好的情侣刨开，那么不能牵手的情侣是一组一组的，每组都一定有首尾相连的特点。**
示例：（这里的12代表情侣代号）
1221；
12 23 34 48 81；
**一定会有一个接龙形式，并且最后回到原点。**
那么，事实上就解决了，在一个首尾相连组的情况下，假设里面有N对情侣，那么最少一定要交换N-1次才可以完成。因为我们必须一对一对的撮合。其实这就想到了数据结构中的连通分量...这个办法有BFS分为一组一组的节点，完成了。或者并查集也是非常好的选择。


# BFS




## 并查集
假定12 23 31根据题意，要想让第二对情侣之间能够成功牵手，要么交换第一对情侣的男生与第二对情侣的男生，要么交换第二对情侣的女生与第三对情侣的女生。

既然存在这两种交换方式，那么有必要两种方式都考虑吗？答案是无需都考虑。不难注意到，无论采用了两种交换方式中的哪一种，最后的结局都是「第二对情侣坐在了一起，且第一对情侣的男生与第三对情侣的女生坐在了一起」，因此两种交换方式是等价的。

这种等价性让我们想到了并查集。

一些语言特性：
vector<int> f(tot, 0);代表tot个大小为0的值。

## 并查集的实现：
想实现并查集，必须要理解他的深层逻辑，即并查集是一棵树。而且是约矮越好的树。但是实现是靠数组来实现的。
手搓并查集pass.

## BFS的实现：
即main.cpp中提供的官解。
首先，n是总人数，tot是总对数。graph是一个二维数组，第x行有两列，分别是情侣二人隔壁的人。下面开始广搜。
如果没去过当前点，给出一个新队列，将当前点置为已经访问，**将当前点放入队列**，然后设置一个新的初始0数字cnt，q不空时取出对头，cnt自加，将q所有没有遍历的邻居情侣入队，然后加入ret.

# 时空复杂度分析
并查集花费了额外的ON空间，时间复杂度ONLOGN，由于路径压缩的帮助，很接近N。
BFS O2N的空间，ON的时间复杂度，因为每个情侣只需要遍历一次。