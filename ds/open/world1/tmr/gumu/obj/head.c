// Room: /d/gumu/obj/silverkey.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("�L�W����", ({"head"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("long","�@���L�W�����šC\n");
                set("value", 0);
                setup();
        }
}


