#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("石板胸甲",({ "stone corslet","corslet" }) );
  set("long",@LONG
兩片薄石板用繩子連接在一起，穿在身上剛好一前一後，看起來頗為
笨拙。
LONG);
  set_weight(4500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "副");
    set("value",0);
  }
  set("armor_prop/armor",15);
  set("armor_prop/dodge",-2);
  setup();
}
