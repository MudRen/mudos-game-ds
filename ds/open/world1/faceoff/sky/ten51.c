#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"霧峰"NOR);
 set("long",@LONG

             這裡一片微綠色的濃霧，你什麼都看不見！！

LONG
    );
 set("exits",([  "south":__DIR__"ten50",
    ]));
set("no_clean_up",0);set("item_desc",([
       "綠色的濃霧":HIG"在濃霧中隱隱約約有一條小徑....\n"NOR,
      "小徑":HIW"小徑在濃霧中若隱若現，你可以走上(walk on) 這條小徑\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_walk","walk");
}
int do_walk(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten52.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "on %s", a )!=1 )
    return notify_fail("指令格式： walk on <地點> .\n");
        if( a!="小徑" )
                return notify_fail("這個方向你走不過去\n");
        message_vision(HIW"$N走進了濃霧之中..。\n"NOR,me);
        me->move(where1);
        return 1;
}
