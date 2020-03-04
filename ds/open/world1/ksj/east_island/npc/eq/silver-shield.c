#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIW"流光銀盾"NOR,({"silver shield","shield"}));
  set("long", @LONG
西方大陸所產的防具，以質輕的鋼鐵嵌上施加魔力的銀片，具有很好
的防護力。
LONG);
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",3);
    set("value",6000);
    set("material","silver");
  }
  set("armor_prop/armor",21);
  set("armor_prop/shield",15);
  set("armor_prop/block",5);
  set("armor_prop/con",1);
  set("armor_prop/int",1);
  setup();
}
