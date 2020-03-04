#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"龍井棧道-斷口"NOR);
 set("long",@LONG
龍井棧道在這裡就結束了, 你眼前只剩下一片峽谷, 而
龍井棧道原本在此轉角只看得到一堆石礫, 彷彿在提醒人們
這裡曾經是經商的主要途徑, 而只有眼前的山壁這靜靜傾聽
....
LONG
    );
 set("exits",([    "south":__DIR__"ten26",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me,where;
        string a;
        me = this_player();

        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要爬到哪裡?\n");
        if( a!="山壁" )
                return notify_fail("這裡沒有這種東西給你爬\n");
        message_vision("$N在山壁上蹦蹦跳跳輕鬆向前行，\n"
                        +"忽然一個轉角失去了身影....?!\n",me);
        me->move(where);
        return 1;
}

