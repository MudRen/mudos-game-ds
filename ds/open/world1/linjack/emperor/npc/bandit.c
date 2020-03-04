inherit NPC;
void create()
{
        set_name("強盜嘍囉",({ "bandit minion","minion","bandit" }));
        set("long",
                "這傢伙看起來一副瘦弱貌, 你實在難以想像他怎麼當強盜的,\n"
                "搶不搶得到錢還真有問題喔。\n"
        );
        set("age",30+random(6));
	set("attitude", "peaceful");
        set("level",10);
	set("battlepoint",1);
	set("evil",3+random(3));
        set("guild_gifts",({ 7,7,3,3 }));
        set("chat_chance",5);
        set("chat_msg",({
  "強盜嘍囉正在盯著你看。\n",
  "強盜嘍囉說: 滾開! 滾開!\n",
  "強盜嘍囉正在一面嘻嘻的笑著, 一面數著搶來的銀兩。\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "強盜嘍囉說: 你想幹什麼! 黑吃黑嗎!?\n",
  (: command("cow") :),
  (: command("angry") :),
}));
        set("wimpy",30);
        setup();
        carry_object(__DIR__"wp/kris")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}
