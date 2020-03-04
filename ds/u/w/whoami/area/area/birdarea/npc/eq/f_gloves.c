#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name(YEL"狐皮"NOR"手套",({"fox gloves","gloves"}));
  set("long", @LONG 
一件用狐狸皮做出來的手套，十分的柔軟也非常的保暖•防禦力
、攻擊力皆會因製作人的不同而有所改變•
LONG);
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",1+random(4));
  set("armor_prop/armor",12+random(7));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",-2); 
  set("armor_prop/str",1);
  set("armor_prop/con",2);
  setup();
}

