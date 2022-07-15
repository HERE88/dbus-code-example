# GDBus-demo

#### 介绍

    gdbus session demo

#### 软件架构

    gdbus的xml提供两个方法和两个信号。  
    客户端生成一个库(libExampleClientlib.so)，暴露出同步方法和异步方法函数，回调的注册函数。 
    
    example文件夹是客户端的一个例程(CltExample)。  
    server文件夹是服务端的例程(SvrExample)。  

#### 编译环境

    Ubuntu 22.04 LTS

#### 安装教程

```bash
    mkdir build
    cd build
    cmake ..
    make
    cpack
```

#### 使用说明

1.  部署dbus
```bash
    dbus-daemon --session --address=unix:path=/tmp/session_bus_socket
    export DBUS_SESSION_BUS_ADDRESS=unix:path=/tmp/session_bus_socket
```
2.  在build目录下执行服务端
```bash
    ./server/SvrExample
```
3.  在build目录下执行客户端
```bash
    ./example/CltExample
```

#### 错误记录
    运行dbus-daemon时如遇如下错误：
        dbus-daemon: /lib/x86_64-linux-gnu/libdbus-1.so.3: version `LIBDBUS_PRIVATE_1.14.0' not found (required by dbus-daemon)  
    说明系统已经安装了dbus，不需要再自行安装，卸载（dbus-1.14.0）即可。  
    
    解决方法：
        在下载的dbus源码安装目录下运行 ```bash$ sudo make uninstall```
 
