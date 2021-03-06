//
//      根據天氣而改變房間的 long 的標準房間
//
//                                                      Create by Caesar

#include <mudlib.h>

inherit ROOM;

#define CONTROL_DAEMON  "/u/c/caesar/temp/tmob"         // 控製房間敘述的物件

mapping room_long = ([
                "day"   : "白天的 long \n",
                "night" : "晚上的 long \n" 
                        ]);

void change_long(string status)
{
        switch(status)
        {
                case "白天" :
                        set("long", room_long["day"] );
                        return;

                case "晚上" :
                        set("long", room_long["night"] );
                        return;

                default :
                        return;
        }
}

void create()
{
        object daemon;
        ::create();
        seteuid(getuid());
        set("long", "原本的 LONG\n" );
        set("short", "原本的 SHORT" );
        set("light", 1 );

        // 如果還沒載入就載入吧
        if( daemon = find_object_or_load(CONTROL_DAEMON) )
                change_long(daemon->query_weather_status());
}
