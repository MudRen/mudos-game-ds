#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(CYN"鐵碎牙"NOR,({"iron-cut dagger","dagger"}));
  set("long",@LONG
以製作太刀的方式製成的短刀，相當銳利而耐用甚至可以削鐵。
LONG);
  set_weight(1100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",25);
    set("unit", "把");        
    set("value",6000);
    set("volume",2);
    set("material","blacksteel");       
  }        
  set("backstab_bonus",40);
  init_dagger(40);
  setup();
}
