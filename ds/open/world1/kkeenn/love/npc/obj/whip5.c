#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIM"夢情鞭"NOR , ({ "dream love whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條粉紅色的鞭子。\n");
    set("material", "silver");
    set("value",4700);
    set("weapon_prop/str",1);
  }
  init_whip(30);
  setup();
}

