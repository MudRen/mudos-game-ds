inherit NPC;
void create()
{
        int a=25;
        set_name("許\彪",({ "hsu biaw","biaw" }));
        set("long",
                "這傢伙就是使用重弩殺人於百丈之外而成名的大盜, 是東郊\n"
                "四大盜排行末尾, 但他的箭術和空手搏鬥之術絕不容小看..!\n"
        );
        set("age",38);
	set("attitude","killer");
        set("level",31);
	set("battlepoint",4);
        set("guild_gifts",({ 6,2,6,6 }));
	set("evil",10+random(6));
        set("apply/armor",25);
        set("chat_chance",10);
        set("chat_msg",({
  "許\彪正在盯著你看。\n",
  (: random_move :),
  "許\彪說: 嗯! 兄弟們! 殺!\n",
  "許\彪正在試拉他的弩。\n",
}));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
  "許\彪說: 我強絕武林的箭術今天就取你性命!\n",
  (: command("shoot") :),
  (: command("shoot") :),
  (: command("wield bow") :),
  (: command("shoot") :),
}));
        setup();
        carry_object(__DIR__"wp/h_crossbow")->wield();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/shoes")->wear();
        carry_object(__DIR__"eq/pants")->wear();
       while ( a >= 0 )  {
        carry_object(__DIR__"wp/s_arrow");
        a--; }
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
        room->set_temp("die/biaw",1);
        room->clean(1);
	::die();
	return;
}
