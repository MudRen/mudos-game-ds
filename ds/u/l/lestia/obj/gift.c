#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("禮物", ({"gift"}));
    set("unit", "個");
    set("long",@LONG
    就是禮物
LONG);

    set_weight(1);
    set("value",1);
  setup();
}
