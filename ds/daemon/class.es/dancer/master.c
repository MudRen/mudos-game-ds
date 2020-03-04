// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void use_poison();

void create()
{
	set_name("�Ť��", ({ "master dancer", "master", "dancer" }) );

	set("title", "�ߤ���D");
	set("nickname", "�^���P�l");
	set("gender", "�k��");
	set("age", 22);
	set("long",
		"�Ť�ӬO�@�ӤQ���X�⪺���k�M�o�u���@��\\�]��O�D�W�d���M�\\�h\n"
		"���J�l�̡M�I�ӻ��ȳ����o�ѤU�L���������P�^���ɭˡC\n");
	set("attitude", "peaceful");
	set("class", "dancer");
	set("apprentice_available", 10);

	set("str", 21);
	set("int", 28);
	set("spi", 26);
	set("per", 30);
	set("cps", 30);

	set("force", 1200);
	set("max_force", 1200);
	set("force_factor", 18);

	set("combat_exp", 1000000);
	set("score", 90000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		"�Ť�ӹ�M�@���M�@���ਭ�w�ۻR�F�_�ӡM�ﲴ�e�o���c�����G������b�ߤW�C\n",
		"�Ť�Ӹ}�B�����M�����a��F�X�Ӱ�M�^���@���C\n",
		"�Ť�ӥΤ�ߤF�ߦۤv���v¯�M���O�ȳQ���I�n���a�C\n",
		"�Ť�ӯ��H�H�a�B�_�a�W�@���q" HIM "�]�@���n" NOR "�W���U����ä�C\n",
		(: use_poison :),
		(: exert_function, "chillgaze" :),
	}) );

	set_skill("unarmed", 40);
	set_skill("sword", 70);
	set_skill("throwing", 100);
	set_skill("force", 30);
	set_skill("parry", 70);
	set_skill("dodge", 100);
	set_skill("literate", 100);
	set_skill("perception", 100);
	set_skill("whip", 100);

	set_skill("stormdance", 100);
	set_skill("tenderzhi", 100);
	set_skill("iceforce", 100);
	set_skill("snowwhip", 90);

	map_skill("dodge", "stormdance");
	map_skill("unarmed", "tenderzhi");
	map_skill("force", "iceforce");
	map_skill("whip", "snowwhip");

	create_family("�ߤ��", 1, "���D");

	set_temp("apply/defense", 100);

	setup();

	carry_object(__DIR__"echowhip")->wield();
	carry_object(__DIR__"snake_sandal")->wear();
	carry_object(__DIR__"gold_belt")->wear();
	carry_object(__DIR__"bloody_dress")->wear();
}

void reset()
{
	delete_temp("learned");
	set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say �C�ۡM�@�Ӥ@�ӨӡC");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say �����D���Ѥw�g���F�Q�ӧ̤l�M���Q�A���{�F�C");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "�k��" )
		command("say �k�H�����O�n�F��M�u�}�T");
	else {
		command("say �ܦn�M�u�n�A�糧���D���߯կաM�n�B�O�֤��F���C");
		if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
			message_vision("$N�ǬN�a���N��$n���y�M���D�R�S�O�O���A�o�˪��k�� ....\n", this_object(), ob);
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "dancer");
	add("apprentice_availavble", -1);
}

void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("rose_poison") ) return;

	tell_object(ob, "�Aı�o�y�W���G�g�W�F����F��M����@�N�o����]�S���C\n");
	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
		ob->apply_condition("rose_poison", 20);
}
