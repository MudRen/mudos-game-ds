#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name(HIG"相柳內丹"NOR, ({ "xiangliu pill","pill" }));
  set("long",@LONG
妖獸  相柳的內丹，散發出濃烈的妖氣，吃了有助傷勢的回復。
LONG
);
  set_weight(50);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("eat_msg",HIW"$N吃下一顆散發妖氣的內丹。"NOR);
    set("eff_msg",HIG "一陣綠光的光芒從你身上發出....\n" 
            + NOR CYN "(你覺的身體狀態好了一些！！)"NOR );
  }
  set("value", 3000);
  set("cure",([
      "body" : 5,
      "head" : 5,
      "left_leg" : 3,
      "right_leg" : 3,
      "left_arm" : 3,
      "right_arm" : 3,
     ]));
  set("heal",([
      "hp"    : 500,
      "mp"    : 200,
      "ap"    : 200,
     ]));
  setup();
}
