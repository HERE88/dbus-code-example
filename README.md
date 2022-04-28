# gdbus_wang

安装dbus：
https://dbus.freedesktop.org/releases/dbus/

下载后
1.  /configure 
2.  make && make install

安装glib2.0：
sudo apt-get install libglib2.0-dev

获取头文件及库位置：
1.  pkg-config --cflags --libs glib-2.0
2.  pkg-config --cflags --libs gio-unix-2.0
