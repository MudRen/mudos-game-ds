#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(CYN"鐵鎖斗蓬"NOR,({ "chain surcoat","surcoat" }) );
  set("long",@LONG
用細鐵鏈製成的斗蓬，雖然防護力很好但是卻很笨重。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(3500);
    set("material", "steel");
    set("unit", "件" );
    set("value",3000);
    set("volume",4);
    set("wear_msg",
        "$N將一件沉重的$n披在肩上，鐵鍊喀啦喀啦作響。\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/dodge", -5);
  set("armor_prop/dex", -2);
  setup();
}
