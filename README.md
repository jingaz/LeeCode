# LeeCode刷题
## 2020/4/6 -->38
- 解数独，回溯法
- priority_queue 优先队列
- bitset<> 位集合操作容器
## 2020/4/9 -->50
- 构造二叉树的算法可用全局变量+递归替换
- 动态规划 要点在于理清[i-1]与dp[i]关系
- 贪心算法 要点在于最值的比较
## 2020/4/13 
- LeeCode的c++编译器有点问题
    
    > intervals.earse(intervlas.begin())    不报错

    > int i=-1;    
    > intervals.earse(intervlas.begin()+i+1);   报错

    后者必须改成 
    > intervals.earse(intervlas.begin()+(i+1));
## 2020/4/14
- 计算第 `k` 个排列，需要康托展开，用蛮力法会超时
## 2020/4/15
- （不同路径）计算组合数边乘边除，避免溢出
## 2020/4/17 
爬楼梯 双百 | 斐波那契数列 | 存在一个数学公式可以直接得出 f(n)，不用计算中间结果，但这里没有使用
## 2020/4/20
最小覆盖子串 int hash[256] 字符哈希表，边吃边吐计数
## 2020/4/21
组合 子集 单词搜索都是典型的dfs+回溯法
## 2020/4/24 
- 柱状图中的最大矩形 单调栈保存元素索引，先计算凹陷下去的bar，栈保持单调递增，最后遇见一个0，从高到低计算每个bar代表的最大矩形
- 85题 最大矩形这个题，分两步 用到84题柱状图中的最大矩形的算法，难点在于问题转化
## 2020/4/24 
- 扰乱字符串  暴力遍历解法 巧妙判断两个字符串的字母组成是否相同
~~~
    if (s1 == s2) {
        return true;
    }
    int N = s1.size();
    int pos[26] = {0};
    for (int i = 0; i < N; i++) {
        ++pos[s1[i] - 'a'];
        --pos[s2[i] - 'a'];
    }
    for (int i : pos) {
        if (i) {
            return false;
        }
    }
~~~

- 格雷码生成公式 `G(i) = i ^ i>>1` ;
- 子集II 去重操作 若前一个元素和当前元素相等 且没有使用，则当前元素也不能使用，应跳过
~~~ 
    if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
        continue;
    }
 ~~~
 - 解码方法 动态规划 只用到前两个值，用pre1、pre2替代dp数组， 初值 pre1=1，涵盖了边界条件
 ## 2020/4/25
 - 不同的二叉搜索树 分别以`1~n`为根节点计算左右子树的数量， G(i)=G(i-1)*G(n-i);