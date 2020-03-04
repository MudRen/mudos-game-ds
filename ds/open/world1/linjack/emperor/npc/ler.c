inherit NPC;
void create()
{
        set_name("李樂",({ "li ler","ler" }));
        set("long",
                "這傢伙就是使用一把罕見的刀杖殺人的箇中高手, 這傢伙也\n"
                "列名東郊四大盜之一, 在黑道中頗有名望.\n"
        );
        set("age",40);
	set("attitude","killer");
         set("level",33);
	set("battlepoint",4);
        set("guild_gifts",({ 6,6,4,4 }));
	set("evil",10+random(6));
        set("apply/armor",15);
        set("chat_chance",15);
        set("chat_msg",({
  (: random_move :),
  "李樂說: 嗯! 兄弟們! 殺!\n",
  "李樂正在休息。\n",
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  "李樂說: 看我的刀杖!\n",
  (: command("wield staff") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/b_staff")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        add_money("gold",1);
}
void die()
{
	object ob,room;
        room = load_object("/open/world1/linjack/emperor/bandit3");
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) { ::die();	return; }
        room->add_temp("pop",([ ob->query("id") : 1 ]));
        room->add_temp("clean",1);
        room->set_temp("die/ler",1);
        room->clean(1);
	::die();
	return;
}
