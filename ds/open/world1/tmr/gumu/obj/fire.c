// Room: /d/gumu/obj/silverkey.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("火折", ({"fire", "_FIRE_"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","枝");
                set("long","一枝火折，可以用來點火照明。\n");
                set("value", 0);
                setup();
        }
}

