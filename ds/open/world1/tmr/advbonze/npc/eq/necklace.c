#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIW"如來佛長項鍊"NOR,({"rulaifo necklace","necklace"}));
  set("long", @LONG  
這是一串裝飾在如來佛像上的長項鍊，只見每粒佛珠上都雕刻著精緻的圖案。
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
  set("limit_lv",25);
  set("armor_prop/armor", 8);
  set("armor_prop/shield", 10); 
  set("armor_prop/int",1); 
  set("armor_prop/dex",1); 
  setup();
}

