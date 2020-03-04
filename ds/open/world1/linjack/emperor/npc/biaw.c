inherit NPC;
void create()
{
        int a=25;
        set_name("�\\�C",({ "hsu biaw","biaw" }));
        set("long",
                "�o�å�N�O�ϥέ������H��ʤV���~�Ӧ��W���j�s, �O�F��\n"
                "�|�j�s�Ʀ楽��, ���L���b�N�M�Ť�i�����N�����e�p��..!\n"
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
  "�\\�C���b�n�ۧA�ݡC\n",
  (: random_move :),
  "�\\�C��: ��! �S�̭�! ��!\n",
  "�\\�C���b�թԥL�����C\n",
}));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
  "�\\�C��: �ڱj���Z�L���b�N���ѴN���A�ʩR!\n",
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
