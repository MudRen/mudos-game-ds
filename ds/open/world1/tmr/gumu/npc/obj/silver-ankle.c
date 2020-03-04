#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name("銀足鍊",({"silver ankle","ankle"}));
  set("long", "這是一條造型典雅的銀足鍊，上頭綁著帶有幾分娟秀的細紅繩子。\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("value", 3000);
    set("material","silver");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 2);
  setup();
}

