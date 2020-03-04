#include <armor.h>
inherit SHIELD;

void create()
{
  set_name("石片盾",({"stone shield","shield"}));
  set("long", @LONG
一片天然的石板，拿來當作盾牌倒是蠻合用的。
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",4);
    set("value",100);
    set("material","stone");
  }
  set("armor_prop/armor",10);
  setup();
}
