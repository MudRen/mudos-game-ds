#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIW"如來佛足鍊"NOR,({"rulaifo ankle","ankle"}));
  set("long", @LONG  
這是一串裝飾在如來佛像上的足鍊，每一粒佛珠上都雕刻著精緻的圖案。
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("value", 4000);
    set("material","gold");
  }
  set("limit_lv",30);
  set("armor_prop/armor", 5);
  setup();
}

