#include <ansi.h>
#include <armor.h>
inherit PANTS;
void create()
{
  set_name(HIR"修羅手套〥"NOR ,({ "shu lo pants","pants" }) );
  set("long","四大塔王之一的燕非彥使用的防具。");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cold");
    set("volume",2);
    set("unit", "條");
    set("value",2100);
  }
  set("armor_prop/armor",10);
  set("armor_prop/con",1);
  setup();
}





