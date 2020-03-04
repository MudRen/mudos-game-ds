// servant.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����ѪZ", ({ "master champion", "champion", "master" }) );
	set("title", "���ϻնǥ\\��");
	set("nickname", "�j�Ѩ�");
	set("gender", "�k��");
	set("age", 54);
	set("long",
		"�����ѪZ�O���ӤW�������M���O�L���ͮ��]�Z�ǡM���@�߱�a�شI\n"
		"�H�������ϻնǥ\\�Ϥ@¾�M�H�K�\\Ū���ϻդ����ê��Z�Ǩ��y�M�L��\n"
		"�A������Z�ǤW�������M�L���ର�A�ѵ��C\n");

	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("force", 4000);
	set("max_force", 2200);
	set("force_factor", 30);

	set("inquiry", ([
		"�Z��": "�Z�Ǥ��D....��....�u�i�N�|�M���i����C\n",
		"���ϻ�": "���ϻդD�O�����Z�L���D�����]�M�A������ƭn���Z�L���D�S\n",
		"���v": "�@....�ѤҦV�Ӧ��ӳW�x�M�Z�O�Q���ڬ��v���M�o���ڤT�ۤ����M�A�Q�ո�(accept test)�S\n"
	]) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�Ѩ���", 15, "�̤l");
	assign_apprentice("�̤l", 0);

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("sword", 80);
	set_skill("blade", 80);
	set_skill("parry", 100);
	set_skill("dodge", 80);
	set_skill("throwing", 50);

	set_skill("celestial", 100);
	set_skill("celestrike", 100);
	set_skill("spring-blade", 80);
	set_skill("pyrobat-steps", 90);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

	setup();

	carry_object(__DIR__"houndbane")->wield();
}

void init()
{
	::init();
	add_action("do_accept", "accept");
}


int do_accept(string arg)
{
	mapping guild;

	if( arg== "test" ) {
		say("\n�����ѪZ�I�F�I�Y�M���D�R�ܦn�M�o�O�Ĥ@��....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("�����ѪZ�ĤF�f��M���D�R�s�Ĥ@�۳������L�M�u�O�ۤ��q�O....\n");
			return 1;
		}
		say("\n�����ѪZ���D�R�o�O�ĤG��....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("�����ѪZ�u��v�a�@�n�M���D�R�K�O���o�\\�h���Ȧ����å�....\n");
			return 1;
		}
		say("\n�����ѪZ���D�R�ĤT�ۨӤF....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0 
		|| !present(this_player(), environment())) {
			say("�����ѪZ�ĹD�R�i���M���D�ѤҤ@���Z�\\���L�ǤH....\n");
			return 1;
		}
		say("\n�����ѪZ�����j���M���D�R����ѤҲש�V�o�@�ӥi�y���~�T\n\n");
		command("recruit " + this_player()->query("id") );
		return 1;
	}
	return 0;
}

