#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name("天狗面具"NOR,({"tengu mask","mask"}) );
  set("long",@LONG
天狗常用的面具，面具上少不了一個長長的紅色鼻子。
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");       
    set("value",400);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",3);
  set("armor_prop/int",1);
  setup();
}
