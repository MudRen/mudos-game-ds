inherit NPC;
void create()
{
        set_name("強盜",({ "bandit" }));
        set("long",
                "這傢伙看起來一副凶巴巴的樣子, 一看就知道不是好貨,\n"
                "不知道犯下過多少件殺人放火的案子。\n"
        );
        set("age",35+random(6));
	set("attitude", "aggressive");
         set("level",18+random(4));
	set("battlepoint",2);
        set("guild_gifts",({ 7,6,3,4 }));
	set("evil",5+random(6));
        set("chat_chance",5);
        set("chat_msg",({
  "強盜正在盯著你看。\n",
  "強盜說: 嗯! 來了個找死的了!\n",
  "強盜正在四處張望著, 不知道在看些什麼。\n",
}));
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
  "強盜說: 兄弟們! 上!\n",
  (: command("say 納命來 ~~~ !") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/cutless")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        add_money("silver",4);
}
