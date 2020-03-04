// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�h�E��", ({ "master swordsman", "swordsman", "master" }) );
	set("nickname", "���B���L");
	set("gender", "�k��" );
	set("age", 44);
	set("str", 27);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 3);

	set("rank_info/respect", "�h�]�D");

	set("long",
		"�h�E���O�Ӭ۷��j�����~���͡M�Y���O�q�L�y�����۪��u��Ĭ�C�v�A\n"
		"�j���q���체�e�o�ӷŤ徧�������~�H���O�a�j�Z�]���]�D�C\n");

	create_family("�ʤs�C��", 13, "�x���H");

	set("combat_exp", 1000000);
	set("score", 200000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.counterattack" :)
	}) );

	set_skill("unarmed", 40);
	set_skill("parry", 120);
	set_skill("dodge", 80);
	set_skill("sword", 150);
	set_skill("force", 40);
	set_skill("literate", 60);

	set_skill("fonxanforce", 60);
	set_skill("fonxansword", 150);
	set_skill("liuh-ken", 60);
	set_skill("chaos-steps", 100);
	set_skill("spider-array", 85);

	map_skill("unarmed", "liuh-ken");
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "chaos-steps");

	set("inquiry", ([
		"�E���Z�]" : "�E���Z�]�O�����ҳСM�b�U�d�Ө�W�M�����x�ʤs����M�����ѤF���H��ӡC",
		"���H���" : "�����{�פ��ɱN�o�Z�]���b�U�⤤�M�ݱo�n�n�ӬݡC",
		"�B�w�S" : "�B�S�̦b�H�ٺިƤw�g���~�F�M�L�h���Ƥ����A���C",
		"name": "�A�J�M���D�ڬO�h�ݥD�M��򤣪��D�ڬO�h�E���S",
		"here": "�o�̫K�O�E���Z�]�C",
	]) );

	setup();
}

void attempt_apprentice(object ob)
{
	if( ((int)ob->query("cor") < 20) 
	||	((int)ob->query("cps") < 20)) {
		command("say �ǼC���H�����x�j�߲ӡM�̧ڬ�" + RANK_D->query_respect(ob) + "�������G���y�S");
		return;
	}
	command("smile");
	command("say �ܦn�M" + RANK_D->query_respect(ob) + "�h�[�V�O�M�L�饲�w�����C\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
