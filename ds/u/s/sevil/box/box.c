#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"保險箱"NOR,({"heaven box","box"}));
        set("unit", "個");
        set("long",@LONG
        
    這是邪仔用來存放一些EQ和WP的箱子.......

  放東西: put [東西] in box
  拿東西: get [東西] from box

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


