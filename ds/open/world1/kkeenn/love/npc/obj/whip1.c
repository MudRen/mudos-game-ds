#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("竹鞭" , ({ "bamboo whip","whip" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條以青竹製成的鞭子。\n");
    set("material", "bamboo");
	set("value", 1700);
    set("weapon_prop/dex",1);
  }
  init_whip(12);
  setup();
}

