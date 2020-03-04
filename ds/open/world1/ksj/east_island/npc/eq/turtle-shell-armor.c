#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("龜殼甲",({ "turtle-shell armor","armor" }) );
  set("long",@LONG
巨大的烏龜空殼，剛好可以讓人套進去，不過看起來並不好看就是了
。
LONG);
  set_weight(4500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "件");
    set("value",1000);
  }
  set("armor_prop/armor",17);
  set("armor_prop/dodge",-4);
  setup();
}
