#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("妖魂珠", ({"bogle bead","bead"}) );
  set("long",@LONG
蘊含妖怪法力的珠子，有時在妖怪死亡後會出現。
LONG
);
  set_weight(30);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("eat_msg","$N吃下一顆隱泛綠光的小珠子。");
    set("eff_msg",HIG "你覺得有股冷流在全身經脈流竄，使你渾身舒暢。" NOR );
    set("unit", "顆");
    set("volume",1);
    set("value",500);
  }
  set("heal",([
      "ap": 150,
      "mp": 150,
     ]));
  setup(); 
}
