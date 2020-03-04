#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(RED"鬼怒面具"NOR,({"angry mask","mask"}) );
  set("long",@LONG
以惡鬼臉骨製成的面具，面具上長長的鬼角代表這頭骨曾經是鬼力強
大的鬼所有。
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",50);
    set("limit_lv",40);
    set("unit", "張");       
    set("value",7000);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",5);
  set("armor_prop/int",-1);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/wit",-1);
  set("armor_prop/bar",1);
  setup();
}
