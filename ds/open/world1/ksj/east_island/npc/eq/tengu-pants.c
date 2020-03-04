#include <armor.h>
inherit PANTS;

void create()
{
  set_name("天狗褲" ,({ "tengu pants","pants" }) );
  set("long","一件寬鬆的長褲，上面染著五彩的顏色。");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",1);
    set("unit", "條");
    set("value",500);
  }
  set("armor_prop/armor",2);
  set("armor_prop/shield",3);
  set("armor_prop/dex", 1);
  setup();
}
