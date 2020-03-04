#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIG "四海游龍盾" NOR,({"sea-dragon shield","shield"}));
  set("long", @LONG
這是一面用大塊生鐵配合精鋼做成的大盾，上面畫有四條悠遊於雲
中的神龍，所以又稱四海游龍盾，質地堅硬無比。
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume", 4);
    set("value", 8000);
    set("material","iron");
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 5);
  set("armor_prop/con",1);
  set("armor_prop/dex",1);
  setup();
}

