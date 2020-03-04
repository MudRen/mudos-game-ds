#include <armor.h>
inherit SHIELD;
void create()
{
  set_name("木盾" ,({ "wooden shield","shield" }) );
  set("long","普通的木製圓盾，質輕耐用。");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "面");
    set("value",800);
  }
  set("armor_prop/armor",10);
  setup();
}