#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIC"霸天鞭"NOR , ({ "ba tan whip","whip" }) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條青色的鞭子。\n");
    set("material", "silver");
    set("value",4000);
    set("weapon_prop/str",1);
    set("weapon_prop/dex",1);
  }
  init_whip(25);
  setup();
}

