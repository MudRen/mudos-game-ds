#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"百寶箱"NOR,({"box"}));
        set("unit", "個");
        set("long",@LONG

  裝有很多怪東西的箱子，也是宵小窺覬的目標•

  放東西: put [東西] in box
  拿東西: get [東西] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        setup();
}
