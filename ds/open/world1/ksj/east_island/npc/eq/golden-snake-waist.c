#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIY"金鱗蟒帶"NOR ,({ "golden-snake waist","waist" }) );
  set("long",@LONG
赤眼金鱗的蛇皮製成的腰帶，金光閃閃地。
LONG);
  set_weight(900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "條");
    set("value",5000);
  }
  set("limit_con",25);
  set("armor_prop/armor",3);
  set("armor_prop/dex",2);
  set("armor_prop/con",2);
  set("armor_prop/str",1);
  set("armor_prop/int",-2);
  setup();
}
