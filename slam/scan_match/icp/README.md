# ICP 算法

- Iterative:迭代的是什么,迭代的是旋转矩阵R和平移向量t,我们需要使用迭代方法计算他们的增量。
- closest: 最近的,定义两个点集中对应点的距离最近,可以使用欧式距离

> ICP算法步骤
1. 设定一个初始的R,t
2. 根据欧式距离计算对应的最近点 《--PI-ICP， PL-ICP--》 为当前激光帧中的每一个点，找到其最近的两个点j1和j2
3. 根据误差函数，最近点对，使用迭代方法比如LM计算R和t的增量
4. 对R,t进行更新，重新计算误差函数
5. 对误差函数进行判断，满足a.误差小于阈值 或 b.超过最大迭代次数 则退出，否则重回３继续使用LM方法计算R和t的增量。

## csm (ICP c语言实现的库)
注： 不是 correlative scan matching
[]()
## laser_scan_matcher (ros中ICP包，是用了csm的PL-ICP)
[]()

## 参考
[PI-ICP算法的原理与实现](https://blog.csdn.net/kksc1099054857/article/details/80280964)
[多种ICP算法](https://blog.csdn.net/shoufei403/article/details/102972842)
