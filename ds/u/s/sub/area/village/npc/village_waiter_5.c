#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("陳老婆婆" , ({"old woman cheng","old","woman","cheng"}) );
        set("level",5);
        set("race","人類");
         set("gender","女性");
        set("age", 63);
        set("no_fight",1);
        set("long",@LONG
她是這裡最慈祥的老婆婆，常常會熱心地招待外地來的旅客，讓出門
在外的旅客也能感受到有如在家鄉般的溫暖。
LONG);
        set("sell_list",([
         __DIR__"obj/come_best" : 20,
         __DIR__"obj/oreo" : 20,
         __DIR__"obj/fantasy_pill" : 20,
        ]) );
        setup();
}
void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
