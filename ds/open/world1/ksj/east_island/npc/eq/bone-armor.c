#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("骨甲",({ "bone armor","armor" }) );
  set("long",@LONG
用許多骨頭串成的盔甲，隱隱帶有屍氣。
LONG);
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "組");
    set("value",600);
  }
  set("armor_prop/armor",15);
  set("armor_prop/str",1);
  set("armor_prop/int",-1);
  setup();
}
