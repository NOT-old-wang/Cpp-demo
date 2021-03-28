# 内存相关

## RAII
也称 SBRM, 是范围绑定资源管理的缩写
- 演化 (手动申请&&释放 --> GC垃圾收集回收 3倍效率 --> RAII)
- 资源在初始化的时候申请，在不使用后释放


## 拷贝相关
[零拷贝](https://mp.weixin.qq.com/s?__biz=MzUxODAzNDg4NQ==&mid=2247485624&idx=1&sn=248eca4d8dd214126fb89d75acb5f34e&chksm=f98e4c12cef9c5048810530b04d6f58cd449649ffd1372d1eef8f3c3b1592598579ef15f45e0&mpshare=1&scene=1&srcid=11018GENe8rbTX2kAA6R5Xny&sharer_sharetime=1604205133041&sharer_shareid=cca181e4b30561c901e30c39eedf541d&exportkey=ASQbL%2BVkE%2FRQbfDhzAElDNI%3D&pass_ticket=E%2Bv9uFn8SrIXuRBjDwakhJ0W8%2FFEFrMGYXi1ikXnp1IAzwuZpJiblyK3CRLCHRZx&wx_header=0#rd)

## 操作系统对内存的操作
[虚拟内存和物理内存](https://mp.weixin.qq.com/s/HJB_ATQFNqG82YBCRr97CA)

## 经验
memcpy 拷贝普通指针 和 结构体/类内的指针 不一样
doube copy 耗时20us
vector 的效率是 map的6倍