#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW+BLK"陰"HIY"陽"NOR"鐵石", ({ "sun-moon iron stone", "stone" }));
  set("long",@LONG
一顆平凡的石頭，真不知道誰會想要這種東西•
LONG);
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}


