#include <armor.h>
inherit PANTS;
void create()
{
  set_name("絲綢長褲" ,({ "skin pants","pants" }) );
  set("long","這絲綢長褲重頭到尾,都是用百分之百純絲所製,所以這褲子穿起來十分舒服.");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silk");
    set("volume",3);
    set("unit", "件");
    set("value",2200);
    set("limit_lv",10);

  }
  set("armor_prop/armor",8);
  set("armor_prop/con",1);
  
setup();
}

