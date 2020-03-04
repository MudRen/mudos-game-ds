#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIC"鹿皮靴"NOR, ({ "boots" }) );
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一雙用藍色鹿皮製成的靴子，看起來蠻好看的。\n");
    set("unit", "雙");
    set("material","fur");
    set("value",3000);
    set("armor_prop/dex",2);
    set("armor_prop/shield",1);
    set("armor_prop/armor", 6);
  }
  setup();
}
