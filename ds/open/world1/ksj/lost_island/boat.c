#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("石舟", ({"stone boat","boat"}) );
        set("long",@LONG
    一條石製的無蓬小船，正停靠在港邊，有股神奇的力量使它浮在
海面上，你可以試著搭上石舟(ferry)。
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "個");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
        add_action("do_ferry","ferry");
}

int do_ferry(string str)
{
        object me,z;
        me=this_player();
 
        if(!str || str!="boat") return 0;
        if(me->query_temp("ride"))
        {
         write("你的座騎往後退了幾步，好像不願意上石舟..\n");
         return 1;
        }
        if(!objectp(z=present("sea stone",me) ) )
        return notify_fail("石舟突然飄離岸邊，你無法上去。 \n");
        destruct(z);
        message_vision(
        HIC"\n$N身上發出一陣藍色光芒，石舟也呼應似的發光，隨即$N登上了石舟。\n"NOR
        HIC"\n$N身上的碧海石飛出嵌在石舟的小平臺上，石舟像是得到動力似的朝海上急駛！\n"NOR,me);
        me->move(__DIR__"stone-boat");
        destruct(this_object());
        return 1;
}
