#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"劍草叢"NOR);
 set("long",@LONG
劍草到處都有, 但這裡的劍草卻更茂盛的奇異, 似乎又
人刻意在栽種它們, 你不禁開始懷疑會是什麼人在龍井棧道
旁邊去種植毫無用處的劍草? 
LONG
    );
set("exits",([   "up":__DIR__"ten26",
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
        where1 = load_object(__DIR__"ten42");
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

