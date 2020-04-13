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