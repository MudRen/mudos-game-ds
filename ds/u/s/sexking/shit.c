#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"抓狂馬桶內部");
        set("long", @LONG
你已經被吸到抓狂馬桶內部了...只見附近天旋地轉...尿艘屎臭
通通聞的到.........
你感覺到自己快要窒息了.....
LONG
        );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
        add_action("do_fly","fly");
}
int do_fly(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIW"$N突然招喚出一個洗澡器洗了個澡就消失不見了！！。\n"NOR,me);
        me->move(__DIR__"workroom2");
        me->set_temp("the-shit",1);
        return 1;
}

