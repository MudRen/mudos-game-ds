#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIR"龍蝦護手"NOR,({ "lobster wrists","wrists" }) );
  set("long",@LONG
龍蝦殼製成的護手，防禦力沒有金屬製品好，但是很輕。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(500);
    set("material", "leather");
    set("unit", "副");
    set("value",500);
    set("volume",1);
  }
  set("armor_prop/armor", 4);
  set("armor_prop/dex",1);
  set("limit_con",10);
  setup();
}
