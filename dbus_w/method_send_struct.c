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



void sendStruct(){
        printf("Begin sendStruct\n");

        DBusError       err;
        DBusMessage     *msg;
        DBusMessageIter args;
        DBusMessageIter subarg;
        DBusConnection  *conn;

        DBusMessageIter subarg2;

        myMsgType dataSend;
        dataSend.bolArg = TRUE;
        dataSend.strArg = "HELLOWORDD!";
        dbus_int32_t temp[] = {10,9,8,7};
        dataSend.arrIntArg = temp;


        dbus_error_init(&err);
        conn = dbus_bus_get_private(DBUS_BUS_SESSION, &err);

        if (dbus_error_is_set(&err)){
                fprintf(stderr, "Connection Error(%s)\n", err.message);
                dbus_error_free(&err);
        }

        if (NULL == conn){
                fprintf(stderr, "connection point to NULL\n");
                exit(1);
        }


        /*
        DBUS_EXPORT DBusMessage * dbus_message_new_method_call  (   const char *    destination,
                                                                    const char *    path,
                                                                    const char *    iface,
                                                                    const char *    method
                                                                    )
        */
        msg = dbus_message_new_method_call("test.method.server",
                                           "/test/method/Object",
                                           "test.method.Type",
                                           "Method");

        if (NULL == msg){
                fprintf(stderr, "Message Null\n");
                exit(1);

        }

        dbus_message_set_no_reply(msg, TRUE);

        dbus_message_iter_init_append(msg, &args);  // 将迭代器（初始化）绑定至消息
        dbus_message_iter_open_container(&args, DBUS_TYPE_STRUCT, NULL, &subarg);
        // for bool
        dbus_message_iter_append_basic(&subarg, DBUS_TYPE_BOOLEAN, &dataSend.bolArg);
        // for char *
        dbus_message_iter_append_basic(&subarg, DBUS_TYPE_STRING, &dataSend.strArg);

        // for int[] --由于数组不是基本类型，无法用*_append_basic函数来append，需开启新的子迭代
        dbus_message_iter_open_container(&subarg, DBUS_TYPE_ARRAY, "i", &subarg2);
        dbus_message_iter_append_fixed_array(&subarg2, DBUS_TYPE_INT32, &dataSend.arrIntArg, 3);

        // 最后要关闭子迭代，实际上是将子迭代的数据加载到了父迭代器上
        dbus_message_iter_close_container(&subarg, &subarg2);
        dbus_message_iter_close_container(&args, &subarg);

        if (!dbus_connection_send(conn, msg, NULL)){
                fprintf(stderr, "Out Of Memory!\n");
                exit(1);
        }

        dbus_connection_flush(conn);
        dbus_message_unref(msg);

        printf("End sendStruct\n");
}

int main(int argc, char *argv[])
{
    sendStruct();
}
