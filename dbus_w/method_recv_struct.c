#include <dbus-1.0/dbus/dbus.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct __myMsgType{
        dbus_bool_t bolArg;
        char *strArg;
        dbus_int32_t  *arrIntArg;
}myMsgType;


void recvStruct()
{
    printf("Begin recvStruct\n");

    DBusError       err;
    DBusMessage     *msg;
    DBusMessageIter ags;
    DBusMessageIter subags;
    DBusConnection  *conn;

    DBusMessageIter subags2;

    dbus_int32_t    ret;

    // my struct   -- by WHT 20220119
    dbus_bool_t boolArg;
    char *strArg;
    dbus_int32_t  *intArrayArg;

    dbus_error_init(&err);

    conn = dbus_bus_get_private(DBUS_BUS_SESSION, &err);

    if (dbus_error_is_set(&err)){
            fprintf(stderr, "Connection Error (%s)\n", err.message);
            dbus_error_free(&err);
    }

    if (NULL == conn){
            fprintf(stderr, "Connection Null\n");
            exit(1);
    }

    ret = dbus_bus_request_name(conn, "test.method.server", DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
    if (dbus_error_is_set(&err)){
            fprintf(stderr, "Name Error (%s)\n", err.message);
            dbus_error_free(&err);
    }

    if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret){
            fprintf(stderr, "Not Primary Owner (%d)\n", ret);
            exit(1);
    }

    int receivetime = 0;

    while (true)
    {
        dbus_connection_read_write(conn, 0);
        msg = dbus_connection_pop_message(conn);

        if (NULL == msg)
        {
            usleep(1000*1000);
            //printf("waiting 1s\n");  // Add by WHT 20220119
            continue;
        }

        if (dbus_message_is_method_call(msg, "test.method.Type", "Method"))
        {
            printf("receive a method call \n");
            if (!dbus_message_iter_init(msg, &ags))
            {
                fprintf(stderr, "Message has no arguments\n");
            }

            dbus_message_iter_recurse(&ags, &subags); // 将迭代器中打包的数据解开给子迭代

            dbus_message_iter_get_basic(&subags, &boolArg);

            dbus_message_iter_next(&subags); // 步进，相当于指针指向下个数据
            dbus_message_iter_get_basic(&subags, &strArg);

            dbus_message_iter_next(&subags);  // Must!!  --by WHT 20220119

            dbus_message_iter_recurse(&subags, &subags2); // 解开下层迭代
            int intNum;
            dbus_message_iter_get_fixed_array(&subags2, &intArrayArg, &intNum); // 获得数组指针以及元素个数

            // dbus_message_iter_get_arg_type(&args) == DBUS_TYPE_STRING
            // 由上代码可知，无论做否数据类型的判断，传输数据的格式发送与接收双方应该定义好。
            // Linux上的DBus-GLib支持对于xml定义的解析自动生成头文件，方便的解决了这个问题。


            printf("receive a struct : \n"
                   "    bool : %d\n"
                   "    str : %s\n"
                   "    int[] : %d %d %d\n"
                   "    int num : %d\n",
                   boolArg,
                   strArg,
                   intArrayArg[0],intArrayArg[1],intArrayArg[2],
                   intNum);
            //break;  // continue by WHT 20220119

            //对于传输数据的内存释放，除了传送的具体数据外，迭代器不需专门释放，但是消息需要解引用
            dbus_message_unref(msg);
        }

        printf("receive time : %d\n", receivetime++);
    }

    printf("ends recvStruct\n");
}

int main(int argc, char *argv[])
{
    recvStruct();
}
