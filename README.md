下载dbus源码：
https://dbus.freedesktop.org/releases/dbus/

下载后解压，编译，安装：
1. $ ./configure 
2. $ make
3. $ sudo make install

安装glib2.0：
$ sudo apt install libglib2.0-dev

补充：
1. 如果./configure时遇到pkg-config找不到：#sudo apt install pkg-config
2. 如果./configure时遇到expat错误：#sudo apt install libexpat1-dev


获取头文件及库位置：
1. $ pkg-config --cflags --libs glib-2.0
2. $ pkg-config --cflags --libs gio-unix-2.0
