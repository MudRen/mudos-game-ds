inherit NPC;
void create()
{
        set_name("����",({ "do jur","jur" }));
        set("long",
                "�L�N�O�c�W�L��, �b�t�v�W��U�a�����H�����j�s�Y�Y,\n"
                "�L���@���������Z�\\, �L���Z�\\�i��u������U�j���x��,\n"
                "�[�W�L�H�ⲳ�h, �S�O�F���|�j�s����, �`�M�L�T�W�̥S�@\n"
                "�P�i�h, �h��ϥL�̪��������̦��ˤQ�ƤH, ���̴N���˺G\n"
                "���Ʀܩ�n�Ѵ�����. �s�W���d�j�x���ҳo���H����P��\n"
                "�ܿ�, �A�N���D�L�̪���O���h���p�F.\n"
        );
        set("title","�B�@���H");
        set("age",45);
	set("attitude","aggressive");
        set("level",47);
	set("battlepoint",6);
        set("guild_gifts",({ 6,6,4,4 }));
	set("evil",15+random(6));
        set("apply/armor",30);
        set("chat_chance",5);
        set("chat_msg",({
  "�������b�n�ۧA�ݡC\n",
  "������: ��! ��! �O���L�]�F!\n",
  "�������b�ݵۮ�W���ϡC\n",
}));
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
  "������: �ݧڿB�@���M���F�`!\n",
  (: command("wield blade") :),
  (: command("angry") :),
}));
        setup();
        carry_object(__DIR__"wp/blade3")->wield();
        carry_object(__DIR__"eq/leggings")->wear();
        carry_object(__DIR__"eq/t_boots")->wear();
        carry_object(__DIR__"eq/pants")->wear();
        carry_object(__DIR__"eq/t_cloth")->wear();
        add_money("gold",2);
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
        room->set_temp("die/jur",1);
        room->clean(1);
	::die();
	return;
}
