#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("武器商人" , ({ "weaponer" }) );
        set("level",10);
        set("race","人類");
        set("age", 30);
        set("long","你眼前的男子正在櫃檯前坐著，一個賊頭賊腦的男子，你可以向他買武器。\n");
set("sell_list", ([
__DIR__"wp/gun" : 1,
__DIR__"wp/clip" : 1,
]));
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
