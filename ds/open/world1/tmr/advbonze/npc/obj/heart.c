// An example doll.c
// "undead_item" 此name請勿亂用.

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"如來佛心"NOR,({"rulaifo heart","heart","undead_item"}));
                set("long",
"一顆散發著鮮綠光芒的如來佛心，大如人拳，渾圓剔透，\n"
"外表光滑無瑕玼，似乎還正緩緩跳動著。"
                );

        set_weight(100);
                set("value",0);
                  set("no_put",1);
                  set("no_get",1);
                set("unit","顆");
                  set("undead_msg",HIW"\n\t就在$N心臟停止跳動，將要吞下最後一口氣時，$N身上的$n"HIW"突然融入$N的胸腔內！！\n"NOR);
        setup();
}


