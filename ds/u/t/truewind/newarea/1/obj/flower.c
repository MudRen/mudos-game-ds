#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
  set_name(HIM"櫻花"NOR"花瓣",({"sakura petal","petal"}));
  set("long", "一片白裡透紅的櫻花花瓣，十分別緻。\n");
  set_weight(5);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "片");
    set("eat_msg","$N幾口把$n嚼爛，呼嚕給一口吞了下去。");
    set("eff_msg",HIM "你覺得四肢百骸頓時非常舒暢。" NOR );
  }
        set("value", 300);
        set("heal",([
                "hp": 50,
        ]));
        set("cure",([
                "body": 5,
        ]));
        setup();
}