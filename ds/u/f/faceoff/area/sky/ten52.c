#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"小徑"NOR);
 set("long",@LONG
雖然說是小徑，但其實只是一個在濃霧中的空地罷了，
這裡奇怪的冒出了一股寒氣，不知道寒氣是從哪裡冒出來的
？寒冷讓你想離開這裡....
LONG
    );
 set("exits",([  "south":__DIR__"ten50",
    ]));
set("no_clean_up",0);set("item_desc",([
       "洞穴":HIW"寒氣正是從這裡出來的，也許\可以進去看看究竟?\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten53.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
    return notify_fail("指令格式： enter <地點> .\n");
        if( a!="洞穴" )
                return notify_fail("這個地方你進不去\n");
        message_vision(HIW"$N矮身進入了洞穴之中..。\n"NOR,me);
        me->move(where1);
        return 1;
}
