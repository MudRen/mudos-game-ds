#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("女店員" , ({ "salesclerk" }) );
        set("level",10);
        set("race","人類");
        set("age", 30);
set("gender","女性");
        set("long","一個漂亮的女店員在看店，你可以向他購買防具。\n");
set("sell_list", ([
__DIR__"eq/mboots" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
