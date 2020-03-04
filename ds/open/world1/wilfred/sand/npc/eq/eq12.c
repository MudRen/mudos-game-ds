#include <armor.h>
inherit ARMOR;
void create()
{
  set_name("護心鏡" ,({ "heart armor","armor" }) );
  set("long","一面鐵製圓鏡，用皮帶固定在身上，只護住了最重要的心口部分，因此防禦效果有限。");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "iron");
    set("volume",2);
    set("unit", "件");
    set("value",1000);
  }
  set("armor_prop/armor",12);
  setup();
}