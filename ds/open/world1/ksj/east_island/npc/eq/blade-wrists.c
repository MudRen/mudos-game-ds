#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIW"百刃腕輪"NOR,({ "blade wrists","wrists" }) );
  set("long",@LONG
用許多薄刀片製做而成的腕甲，製作的方式非常巧妙而奇特，銳利的
刀片會在攻擊時同時殺傷對手。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1000);
    set("material", "steel");
    set("unit", "副");
    set("value",3000);
    set("volume",2);
  }
  set("armor_prop/armor", 8);
  set("armor_prop/damage",5);
  set("limit_con",20);
  set("limit_int",20);
  setup();
}
