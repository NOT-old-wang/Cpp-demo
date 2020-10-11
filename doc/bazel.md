# bazel
> 

## 编译cpp
1. 建立工作区: 将`WORKSPACE`放在主目录下
2. 模块编译: 每个模块下编写`BUILD`文件
3. bash命令: `bazel build //main:hello-world` (//mian 为主目录下的文件夹, hello-world为需要生成的可执行程序)


## 参考
[官方文档](https://docs.bazel.build/versions/3.5.1/getting-started.html)
[官方cpp_demo翻译](https://blog.csdn.net/elaine_bao/article/details/78668657)
[github](https://github.com/bazelbuild)