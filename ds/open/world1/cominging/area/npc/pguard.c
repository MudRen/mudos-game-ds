#include <ansi.h>
inherit NPC;
void create()
{
	set_name(WHT"官府守衛"NOR, ({ "polity guard","guard" }) );
	set("long","一個平常在大門旁邊守衛的人。\n");
	set("level",25);
        set("age",30);

	set("combat_exp", 24000);
	set("chat_chance", 4);
        set("chat_msg", ({
  (: command,"angry" :),
  (: command,"say 沒有事就快走。" :),
}));

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  HIW"守衛說：反了反了，光天化日之下竟敢群眾打架\n"NOR,
  "守衛說：兄弟們，把他捕了\n"NOR
}));
	set_skill("sword", 50);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);

        setup();
	carry_object(__DIR__"wp/broadsword")->wield();
	carry_object(__DIR__"eq/boots")->wear();
}