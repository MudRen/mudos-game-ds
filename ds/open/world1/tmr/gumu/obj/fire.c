// Room: /d/gumu/obj/silverkey.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("����", ({"fire", "_FIRE_"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","�K");
                set("long","�@�K����A�i�H�Ψ��I���ө��C\n");
                set("value", 0);
                setup();
        }
}

