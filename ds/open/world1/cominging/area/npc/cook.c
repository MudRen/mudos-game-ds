#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老廚",({ "cook" }));
	set("long","一個年紀已老邁的廚師。\n");
	set("race","人類");
	set("age",32);
	set("level",6 );
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"sweat" :),
  (: command,"say 好忙呀！" :),
  (: command,"客倌說個笑話來聽聽吧." :),
  (: command,":)" :),
}));
	setup();
	add_money("coin",20);
}