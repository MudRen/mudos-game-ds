#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name( RED "紅色皮褲" NOR ,({ "leather pants","pants" }) );
  set("long",@long
  一對深紅色皮製褲管，看起來像極了喇叭褲。
long
);  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",2);
    set("unit", "對");
    set("value",1);
  }
  set("armor_prop/armor",4);
  set("armor_prop/dex",1);
  set("armor_prop/shield",2);
  setup();
}

int query_autoload() { return 1; }

