#include <ansi.h>
#include <armor.h>
inherit LEGGING; 
void create()
{
  set_name(YEL"狐骨"NOR"脛甲",({"fox leggings","leggings"}));
  set("long", @LONG 
一件用狐狸的頭骨頭做出來的脛甲，依著狐狸的腳骨做成的•防
禦力會因製作人的不同而有所改變•
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",12+random(6)); 
  set("armor_prop/shield",1+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/int",-2);
  setup();
}

