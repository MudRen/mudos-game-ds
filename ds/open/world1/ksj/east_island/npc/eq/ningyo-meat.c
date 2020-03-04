#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("人魚肉", ({ "ningyo meat","meat" }));
  set("long",
      "一塊人魚肉，據說吃了可以長生不死。\n"
     );
  set_weight(800);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "塊");
  }
  set("value", 2000);
  set("heal",([
      "hp": 1000,
     ]));
  set("cure",([
      "body": 50,
      "right_arm": 50,
      "left_arm": 50,
      "right_leg": 50,
      "left_leg": 50,
      "head": 50,
     ]));
  setup();
}
