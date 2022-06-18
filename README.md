下载dbus源码：
https://dbus.freedesktop.org/releases/dbus/
如在linux下可直接通过命令下载相应的包：
wget https://dbus.freedesktop.org/releases/dbus/dbus-1.14.0.tar.xz

下载后解压：
xz -d dbus-1.14.0.tar.xz
tar xvf dbus-1.14.0.tar

编译，安装：
1. $ ./configure   (如遇No package 'expat' found，需要 sudo apt-get install libexpat1-dev)
2. $ make
3. $ sudo make install

获取dbus头文件及库位置：
pkg-config --cflags dbus-1 --libs dbus-1

安装glib2.0：
$ sudo apt install libglib2.0-dev

获取glib2.0有关的头文件及库位置：
1. $ pkg-config --cflags --libs glib-2.0
2. $ pkg-config --cflags --libs gio-unix-2.0
