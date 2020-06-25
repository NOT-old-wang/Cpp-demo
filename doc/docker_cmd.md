# docker 命令
- 帮助
```bash
$ docker --help
```
## 云
- 查找网上的镜像
```bash
docker search centos
```
## 镜像相关
- 查看已有仓库镜像
```bash
$ docker images
```
- 拉取远程镜像
```bash
$ docker pull ubuntu
```
- 删除镜像
```bash
$ docker rmi hello-world
```
- 创建镜像 更新镜像
1. 从docker 镜像仓库中下载的镜像, 如上面的拉取远程镜像
2. 从已经创建的容器中更新镜像，并且提交这个镜像
3. 使用`Dockerfile`指令来创建一个新的镜像， 文档下方说明
```bash
# 更新镜像
# -m:提交的描述信息; -a:指定镜像作者;  e218edb10161：容器ID; test/ubuntu:v2:目标镜像名
$ docker commit -m="has update" -a="user" e218edb10161 test/ubuntu:v2
```
- 提交镜像到远程
```bash
# <username> 填 docker hub 的用户名
$ docker push <username>/ubuntu:16.04
```
- 修改镜像名
```bash
docker tag <old name> <new name>
```

## 容器相关
-  查看当前容器
```bash
$ docker ps -a
```
- 启动容器
```bash
# -i: 交互式操作; 
# -t: 终端; 
# -d: 服务后台运行;
# -h HOSTNAME 或者 --hostname=HOSTNAME： 设定容器的主机名，它会被写到容器内的 /etc/hostname 和 /etc/hosts
# --dns=IP_ADDRESS, 如：--dns=114.114.114.114 添加 DNS 服务器到容器的 /etc/resolv.conf 中，让容器用这个服务器来解析所有不在 /etc/hosts 中的主机名。
# ubuntu: ubuntu 镜像;  /bin/bash：放在镜像名后的是命令，这里我们希望有个交互式 Shell，因此用的是 /bin/bash; 退出 exit
$ docker run -it ubuntu /bin/bash
```
- 开启已停止的容器 + CONTAINER ID
```bash
docker start b750bbbcfd88
```
- 停止一个容器
```bash
$ docker stop <CONTAINER ID>
```
- 进入容器
```bash
# docker attach: 
# docker exec: 推荐，退出不导致容器停止
$ docker exec -it 243c32535da7 /bin/bash
```
- 删除容器
```bash
$ docker rm -f 1e560fca3906
$ docker container prune  # 清理掉所有处于终止状态的容器
```
- 导出和导入容器
```bash
# TODO
```

## dockerfile 相关
[参考](https://www.cnblogs.com/edisonchou/p/dockerfile_inside_introduction.html)
### 使用
- 构建镜像
```bash
$ docker build -t <镜像名> <路经>
```

### 语法
```dockerfile
# from表示从那个基础镜像开始构建镜像。基础镜像来自仓库python2，版本v0.1
# from必须作为dockerfile的第一行，若本地仓库没有相关镜像，默认从远程仓库获取。如果不执行版本号，默认使用latest基础镜像。
FROM python2:v0.1

# 镜像维护者个人信息
MAINTAINER YouShow

# 安装项目需要的依赖，如果从git仓库安装，要用到git账号和密码
RUN pip install flask
RUN pip install git+http://username:password@gitlab.maixunbytes.com/zhangxiaopeng/pipelines.git
RUN pip install git+http://username:password@gitlab.maixunbytes.com/zhangxiaopeng/mxspider.git
RUN pip install git+http://username:password@gitlab.maixunbytes.com/zhangsheng/dateformatting.git

# 容器启动后，切换到指定目录作为工作目录
WORKDIR /src/spiders/app_zxp_week_2/

# 从源系统的文件复制到容器系统上。示例中复制当前目录下的spiders文件夹到容器系统src文件夹下。要把构建进镜像的文件放到Dockefile文件目录或者子目录下。
# ADD 和COPY使用类似
COPY ./spiders /src/spiders

# 容器执行操作用哪个账户
USER dingyong

# entrypoint用来说明当使用docker run启动容器时候要执行的命令
ENTRYPOINT bash bbs_funcs.sh run_spider siku

# CMD用来表示镜像要运行的默认命令，以及想要传递给它的选项。如果没有指定ENTRYPOINT，当容器启动的时候默认运行的就是CMD的值所指定的命令。若有ENTRYPOINT，ENTRYPOINT是要运行的命令，CMD的值当作ENTRYPOINT的选项。
# CMD 命令会被docker run --it name /command 中command命令覆盖，而ENTRYPOINT不会
# CMD [“cat”, “/etc/hosts”, “/etc/os-release”]注意：RUN指令设置的命令仅在构建镜像的时候会被使用，CMD和ENTRYPOINT会在执行docker run的时候被使用。
CMD

# 设置环境变量
ENV DB_USER=root
```

## docker compose 相关
- Compose 是用于定义和运行多容器 Docker 应用程序的工具。通过 Compose，您可以使用 YML 文件来配置应用程序需要的所有服务。然后，使用一个命令，就可以从 YML 文件配置中创建并启动所有服务