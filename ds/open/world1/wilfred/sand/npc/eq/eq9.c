#include <armor.h>
inherit PANTS;
void create()
{
  set_name("獸毛皮褲" ,({ "beast pants","pants" }) );
  set("long","這獸皮褲色彩斑斕，原來是由虎皮所製，穿上這褲子虎虎生威，似乎人也高大了起來。");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "條");
    set("value",1200);
  }
  set("armor_prop/armor",10);
  setup();
}