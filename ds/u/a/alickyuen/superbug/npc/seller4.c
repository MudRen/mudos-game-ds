#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("常溫" , ({ "chang wen","chang","wen" }) );
        set("level",10);
        set("race","人類");
        set("age", 30);
        set("long","他是在這間速食屋裡工作的員工，你可以向他買你想吃的東西。\n");
set("sell_list", ([
__DIR__"obj/sandwich" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
