#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("碎石片", ({"broken stone","stone"}));
  set("long",@LONG
一塊破碎的石板，石板上畫了一些圖案，看起來像是一群人追著一隻
有著兩隻長牙的巨大老虎，之後巨虎落入冰河結成冰，然後是許多人
慶祝的圖案。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "個");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
