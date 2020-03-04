#include <ansi.h>
#include <armor.h>
inherit BOOTS; 
void create()
{
  set_name(YEL"狐皮"NOR"靴",({"fox boots","boots"}));
  set("long", @LONG 
一雙用狐狸的皮毛做出來的靴子，摸起來十分柔軟•防禦力會因
製作人的不同而有所改變•
LONG);
  set_weight(1700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",4800);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",13+random(6)); 
  set("armor_prop/shield",6+random(4));
  set("armor_prop/dex",2);
  set("armor_prop/int",-1);
  set("armor_prop/con",1);
  setup();
}

