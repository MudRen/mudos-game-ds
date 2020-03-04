#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name(HIR"火狼毛褲"NOR ,({ "fire-wolf pants","pants" }) );
  set("long","火狼毛皮製成的毛褲，火紅的毛色很令人喜愛，穿起來舒服而輕便。");
  set_weight(1300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "條");
    set("value",3000);
  }
  set("armor_prop/armor",6);
  set("armor_prop/shield",3);
  set("armor_prop/dex", 2);
  setup();
}
