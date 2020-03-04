inherit NPC;
void create()
{
        set_name("�i��",({ "chang lin","lin" }));
        set("long",
                "�o�å�N�O���W���֤M�j�s, �L���֤M�b����W�]��ᦳ�W��,\n"
                "�O�F���|�j�s�Ʀ�ѤG, �Y�A�S������l�̦n���n��L�D��..!\n"
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
  "�i�勵�b�n�ۧA�ݡC\n",
  (: random_move :),
  "�i�ﻡ: ��! �S�̭�! ��!\n",
  "�i�勵�b���L���M�C\n",
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  "�i�ﻡ: ����! �g��ڪ��֤M!\n",
  (: command("say �ǩR�� ~~~ ! \n") :),
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
