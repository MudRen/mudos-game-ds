#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(HIY"虎紋"NOR"長褲",({"tiger-strip pants","pants"}));
  set("long", @LONG  
一條有著老虎斑紋的長褲，摸起來軟綿綿的，而且還十分的保暖
和透氣，不用說，這也一定是索貝克的傑作之一•
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",4);
    set("value",3400);
    set("material","fur");
  }
  set("limit_lv",28);
  set("armor_prop/armor",8); 
  set("armor_prop/shield",4);
  set("armor_prop/dex",1);
  set("armor_prop/int",1);
  set("armor_prop/con",1);
  setup();
}

