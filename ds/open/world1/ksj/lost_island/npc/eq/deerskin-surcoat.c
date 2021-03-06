#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(HIC"鹿皮披風"NOR,({ "deerskin surcoat","surcoat" }) );
  set("long","水紋鹿皮製成的披風，相當美麗但防禦能力不佳。\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1100);
    set("material", "leather");
    set("unit", "件" );
    set("value",6000);
    set("volume",2);
    set("wear_msg",
        "$N將一件湛藍的$n披在肩上，全身頓時波光閃閃。\n"NOR);
  }
  set("armor_prop/armor", 5);
  set("armor_prop/shield", 5);
  set("armor_prop/dodge", 8);
  set("armor_prop/dex", 2);
  setup();
}
