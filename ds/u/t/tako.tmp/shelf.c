#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"布丁"HIW"筒"NOR,({"poo ding shelf","shelf"}));
        set("unit", "個");
        set("long",@LONG
        
一個用布丁造型做成的盒子,也可以把東西放進去。

  放東西: put xxx in shelf
  拿東西: get xxx from shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(10000);
        setup();
}

