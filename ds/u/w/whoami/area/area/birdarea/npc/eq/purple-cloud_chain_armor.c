#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(MAG"紫雲鍊甲"NOR,({"purple-cloud chain armor","armor"}));
  set("long", @LONG
這是一件用紫水晶作成的護甲，這些水晶在陽光的折射下會散發
出幽幽的紫光•這件鎧甲也是索貝克親手打造的護具，當年與九
尾作戰的時候他就是穿著這件戰甲•
LONG);
  set_weight(40000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",8);
    set("value",9000);
    set("material","mental");
  }
  set("limit_lv",35); 
  set("limit_str",30); 
  set("limit_con",50); 
  set("armor_prop/show_damage",1);
  set("armor_prop/armor",42);
  set("armor_prop/shield",31); 
  set("armor_prop/dex",-3);
  set("armor_prop/con",2); 
  set("armor_prop/int",2);
  setup();
}

