# gdbus-demo

#### 介绍
gdbus session demo

#### 软件架构
gdbus的xml提供两个方法和两个信号。
客户端生成一个库(libExampleClientlib.so)，暴露出同步方法和异步方法函数，回调的注册函数。
example文件夹是客户端的一个例程(CltExample)。
server文件夹是服务端的例程(SvrExample)。

### 编译环境
Ubuntu 20.04.4 LTS

安装dbus：
https://dbus.freedesktop.org/releases/dbus/
下载后编译：
./configure 
make && make install

安装glib2.0：
sudo apt-get install libglib2.0-dev

#### 安装教程

1.  mkdir build
2.  cd build
3.  cmake ..
4.  make
5.  cpack

#### 使用说明

1.  部署dbus
dbus-daemon --session --address=unix:path=/tmp/session_bus_socket
export DBUS_SESSION_BUS_ADDRESS=unix:path=/tmp/session_bus_socket
2.  在build目录下执行服务端
./server/SvrExample
3.  在build目录下执行客户端
./example/CltExample

