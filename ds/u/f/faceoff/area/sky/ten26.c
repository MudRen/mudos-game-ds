#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"龍井棧道"NOR);
 set("long",@LONG
這裡一反龍井棧道蕭索的氣氛, 卻有如苗家村般長出了
一大叢劍草, 使得這一帶的龍井棧道看起來還頗有古時繁榮
的氣象, 在運輸越趨方便的今朝, 龍井棧道顯得既難行又充
滿了危機, 因此打此過的商旅是越來越少了.
LONG
    );
 set("exits",([  "north":__DIR__"ten27",
                 "south":__DIR__"ten25",
    ]));
set("no_clean_up",0);set("item_desc",([
        "劍草叢":HIG"你實在想不出這樣的劍草叢是幹嘛用的? 通常劍草唯一的功\用是讓人無法穿越(pass), 不過這裡什麼都沒有啊..\n"NOR,
    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me,where1;
        string a;
        me = this_player();
       where1 = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要穿過什麼?\n");
        if( a!="劍草叢" )
                return notify_fail("你眼睛瞎了嗎? 這裡沒有這種東西!\n");
        message_vision(HIW"$N忽然一個轉身失去了蹤影....\n"NOR,me);
      tell_object(me, HIR"你一不小心被劍草給割傷了!\n"NOR);
     me->receive_damage("hp",30);
          me->move(where1);
        return 1;
}

