/* 布店老版(Mercer) */
#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name(HIG"賣布的商人"NOR, ({ "mercer" }) );
	set("long",@LONG
這是一個賣貨正賣得很高興的布商，
你可以用(list)向他尋問有那些布可買(buy)。
LONG
	);
	set("no_fight",1);
	set("chat_chance", 1);
	set("chat_msg", ({
  (: command,"bow" :),
}));
	set("sell_list",([
  __DIR__"obj/cloth.c":3,
  __DIR__"obj/cloth1.c": 4,
  __DIR__"obj/cloth2.c": 5,
  __DIR__"obj/cloth3.c": 3,
  __DIR__"obj/cloth4.c": 4,
  __DIR__"obj/cloth5.c": 4,
  __DIR__"obj/cloth6.c": 4,
]));
	setup();
	add_money("coin",50);
}

void init()
{
	::init(); //忘了加.. @#$%^.. Luky
	add_action("do_buy","buy");
	add_action("do_list","list");
}