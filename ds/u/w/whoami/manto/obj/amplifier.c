inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIY"�����������L�u�X����"NOR, ({ "an amplifier", "amplifier" }));
set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "��");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_use","use");
}
