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
1. system_clock 来自系统范畴实时时钟的挂钟时间, 不稳定的, 完全自动适应本地账户的调节,这种调节可能造成的是，首次调用now()返回的时间要早于上次调用now()所返回的时间，这就违反了节拍频率的均匀分布, windows精度为100纳秒左右
2. steady_clock 决不会调整的单调时钟
3. high_resolution_clock  拥有可用的最短嘀嗒周期的时钟, 精度为1纳秒左右

## 参考
[Linux时间参考](https://haoqchen.site/2019/12/17/linux-time-summary/)

## linux中的时间
### 两种数据结构
1. time_t: `long`类型,用来存储从1970年到现在经过了多少秒，要想更精确一点，可以用结构 `struct timeval`,两个`long`类型
```C
struct timeval
{
    long tv_sec; /*秒*/
    long tv_usec; /*微秒*/
};
```
2. tm: `struct`类型，直接存储年月日的是一个结构
```c
struct tm
{
    int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
    int tm_min;  /*分钟，0-59*/
    int tm_hour; /*小时， 0-23*/
    int tm_mday; /*日，即一个月中的第几天，1-31*/
    int tm_mon;  /*月， 从一月算起，0-11*/
    int tm_year;  /*年， 从1900至今已经多少年*/
    int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
    int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
    int tm_isdst; /*日光节约时间的旗标*/
};
```
### bash命令
```bash
$ date # 输出年月日
$ date +%s # 输出时间戳
$
```