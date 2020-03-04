#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
  set_name(YEL"狐尾"NOR"帶",({"fox belt","belt"}));
  set("long", @LONG
一條用狐狸的尾巴做出來的繫帶，毛絨絨的摸起來真是舒服•防
禦力會因製作人的不同而有所改變•
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",7+random(4)); 
  set("armor_prop/shield",7+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/con",1);
  setup();
}

