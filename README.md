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