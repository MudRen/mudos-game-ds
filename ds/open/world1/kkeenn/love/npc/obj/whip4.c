#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("速鞭" , ({ "fast whip","whip" }) );
  set_weight(1550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條再攻擊時能加速的鞭子。\n");
    set("material", "silver");
	set("value", 3000);
    set("weapon_prop/dex",2);
  }
  init_whip(20);
  setup();
}

