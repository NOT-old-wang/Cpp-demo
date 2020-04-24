## chrono
- c++ 中的时间相关的库
- 包含两部分类模板
```
1: std::chrono::time_point 时间中的点, 绝对时间
2: std::chrono::duration  时间间隔, 相对时间
```
- std::chrono::duration 有一些便利的typedef
```
1: std::chrono::nanoseconds
2: std::chrono::microseconds
3: std::chrono::milliseconds
4: std::chrono::seconds
5: std::chrono::minutes
6: std::chrono::hours
7: std::chrono::days
8: std::chrono::weeks
9: std::chrono::months
10: std::chrono::years
```

- time_point 的时钟有三种
```
1: system_clock 来自系统范畴实时时钟的挂钟时间
2: steady_clock 决不会调整的单调时钟
3: high_resolution_clock  拥有可用的最短嘀嗒周期的时钟
```

## 参考
[Linux时间参考](https://haoqchen.site/2019/12/17/linux-time-summary/)