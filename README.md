#### 下载dbus源码：  
https://dbus.freedesktop.org/releases/dbus/  

#### 如在linux下可直接通过命令下载相应的包：  
```bash
  wget https://dbus.freedesktop.org/releases/dbus/dbus-1.14.0.tar.xz  
```

#### 下载后解压：  
```bash
  xz -d dbus-1.14.0.tar.xz  
  tar xvf dbus-1.14.0.tar  
```

#### 编译，安装：  
```bash
  cd dbus-1.14.0/  
  ./configure  
  make  
  sudo make install  
```
注意！如在configure遇No package 'expat' found，需要安装expat库：```sudo apt-get install libexpat1-dev```   

#### 获取dbus头文件及库位置：    
```bash
  pkg-config --cflags dbus-1 --libs dbus-1  
```

#### 安装glib2.0：  
```bash
  sudo apt install libglib2.0-dev  
```

#### 获取glib2.0有关的头文件及库位置：  
```bash
  pkg-config --cflags --libs glib-2.0  
  pkg-config --cflags --libs gio-unix-2.0  
```
