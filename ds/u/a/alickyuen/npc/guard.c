inherit NPC;

void create()
{
	set_name("小機械人", ({ "robot guard","guard" }) );
	set("long", "由 小小 企業所生產的機械人,負責守衛Naboo城的工作\n");
	set("race","機器人");
	set("age", 100);
	set("level", 20);
                set("chat_msg", ({
  "小機械人說：沒事的就快快走。\n",
}));
                set("chat_chance_combat", 14);
                set("chat_msg_combat", ({
 "小機械人說：反了反了，竟然想打Naboo城的主意?!受死吧\n",
  "小機械人說：兄弟們，把他捕了\n"
}));
                set_skill("unarmed", 100);
	setup();

}
