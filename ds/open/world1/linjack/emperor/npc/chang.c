inherit NPC;
void create()
{
        set_name("張麟",({ "chang lin","lin" }));
        set("long",
                "這傢伙就是有名的快刀大盜, 他的快刀在江湖上也算頗有名氣,\n"
                "是東郊四大盜排行老二, 若你沒有兩把刷子最好不要找他挑戰..!\n"
        );
        set("age",43);
	set("attitude","killer");
         set("level",33);
	set("battlepoint",4);
        set("guild_gifts",({ 8,6,2,4 }));
	set("evil",10+random(6));
        set("apply/armor",15);
        set("chat_chance",8);
        set("chat_msg",({
  "張麟正在盯著你看。\n",
  (: random_move :),
  "張麟說: 嗯! 兄弟們! 殺!\n",
  "張麟正在擦他的刀。\n",
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  "張麟說: 哈哈! 經驗我的快刀!\n",
  (: command("say 納命來 ~~~ ! \n") :),
  (: command("wield blade") :),
}));
        setup();
        carry_object(__DIR__"wp/a_blade")->wield();
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
        room->set_temp("die/chang",1);
        room->clean(1);
	::die();
	return;
}
