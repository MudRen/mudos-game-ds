#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小偷",({ "thief" }));
	set("long","一個常在富宅偷竊的人。\n");
	set("race","人類");
	set("age",32);
	set("level",6 );
	set("chat_chance",10);
	set("chat_msg",({
  HIR"小偷偷偷的往某處走動....\n"NOR,
  (: command,"hehe" :),
  (: random_move :),
}));
	set_skill("dodge",30);
	set_skill("unarmed",30);
	setup();
	add_money("coin",100);
}