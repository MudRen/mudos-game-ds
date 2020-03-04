#include <armor.h>
inherit NECK;
void create()
{
  set_name("柏木護符" ,({ "cypress necklace","necklace" }) );
  set("long","白柏製成的護符，似乎有神力加持於此。");
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",2);
    set("unit", "條");
    set("value",1400);
  }
  set("armor_prop/armor",5);
  set("armor_prop/int",2);
  set("beast_armor_prop/armor",5);
  set("beast_armor_prop/int",2);
  setup();
}
