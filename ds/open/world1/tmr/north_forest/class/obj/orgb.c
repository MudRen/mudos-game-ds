#include <ansi.h>
inherit ITEM;
void create()
{
set_name("材料", ({"org"}));
    set("unit", "個");
set("lione2_join_quest",1);
    set("long",@LONG
    這是鑄劍用的材料之一。
LONG);

    set_weight(1);
    set("value",1);
  setup();
}


