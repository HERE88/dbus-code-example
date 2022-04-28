
SRC := $(wildcard *.c)
DIR := $(notdir $(SRC))
EXC := $(patsubst %.c,%,$(SRC))

#for glib
ADD += $(shell pkg-config --cflags --libs glib-2.0 gthread-2.0)

# for dbus:
ADD := $(shell pkg-config --cflags dbus-1 --libs dbus-1)


all:$(EXC)

%:%.c
	gcc -g $< -o $@ $(CFLAGS) $(ADD)

clean:
	rm -rf $(EXC)

