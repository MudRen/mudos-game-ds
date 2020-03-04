#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(WHT"銀鍊"NOR ,({ "silver necklace","necklace" }) );
  set("long","這是一條銀製的鍊子，閃閃發光，令人愛不釋手。");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",1);
    set("unit", "條");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

int query_autoload() { return 1; }
