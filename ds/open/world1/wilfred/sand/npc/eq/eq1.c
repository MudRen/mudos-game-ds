#include <armor.h>
inherit WAIST;
void create()
{
  set_name("腰纏布" ,({ "woman waist","waist" }) );
  set("long","這是婦女穿的腰帶，通常也有美化身段的功\能。");
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "條");
    set("value",300);
  }
  set("armor_prop/armor",3);
  setup();
}