#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIW"銀甲腰帶"NOR ,({ "silver waist","waist" }) );
  set("long",@LONG
以白銀片層層疊合串接而成的腰帶，具有絕佳的防禦能力。
LONG);
  set_weight(2300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",2);
    set("unit", "條");
    set("value",4000);
  }
  set("limit_con",30);
  set("armor_prop/armor",10);
  set("armor_prop/dodge",-3);
  setup();
}
