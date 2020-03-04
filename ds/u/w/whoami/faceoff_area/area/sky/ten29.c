#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山間的小盆地");
 set("long",@LONG
你不心一個失足掉到這裡來, 這是一個由石灰岩所構成
的盆地, 不要說缺口了, 連個小洞都沒有, 要爬上去簡直是
不可能的事, 在東邊的岩壁上, 只有一小叢劍草, 其他就沒
有什麼東西了....
LONG
    );
set("item_desc",([
        "劍草":HIG"你發現劍草的生根處下面有一個狹窄的岩縫...\n"NOR,
      "岩縫":HIG"這個岩縫大概只能夠讓你勉強通過(pass)....\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("no_recall",1);
set("no_map",1);
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me,where;
        string a;
        me = this_player();
        where = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要穿過什麼?\n");
        if( a!="岩縫" )
                return notify_fail("這裡沒這個東西喔\n");
        message_vision(HIW"$N奮力的從小小的岩縫中擠出去!\n"NOR,me);
      me->move(where);
        return 1;
}


