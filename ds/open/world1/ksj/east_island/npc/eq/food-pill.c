#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("兵籠丸", ({ "food pill","pill" }));
  set("long",
      "用紅蘿蔔、麥粉、糯米粉、蜂蜜、酒，用文火熬乾，然後揉成小丸子\n"
     +"曬乾，吃了除了可以充飢還能獲得足夠的營養。\n"
      );
  set_weight(500);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
  }
  set("value", 200);
  set("heal",([
      "hp": 150,
     ]));
  setup();
}
