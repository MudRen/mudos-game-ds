#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
  set_name(HIY"黃金護腕"NOR,({"gold wrists","wrists"}));
  set("long", @LONG
純金製成的護腕，相當值錢。
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "對");
    set("volume",2);
    set("value",28800);
    set("material","gold");
  }
  set("armor_prop/armor",7);
  setup();
}
