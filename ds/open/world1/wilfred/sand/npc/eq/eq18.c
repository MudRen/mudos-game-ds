#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
  set_name(WHT"銀戒"NOR ,({ "silver ring","ring" }) );
  set("long","這是一條銀製的戒指，閃閃發光，令人愛不釋手。");
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",1);
    set("unit", "只");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

int query_autoload() { return 1; }
