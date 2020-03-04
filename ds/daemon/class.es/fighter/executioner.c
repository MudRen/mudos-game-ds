// executioner.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��x�I", ({ "master executioner", "executioner", "master" }) );
	set("title", "���ϻհ��k��");
	set("nickname", HIC "�� �C �L" NOR);
	set("gender", "�k��");
	set("age", 28);
	set("long",
		"��x�I�O���Z�L���@��ǩ_�ʤH���M�H�L�ȶȤG�Q�K�����~�ֳ��వ��\n"
		"���ϻհ��k�Ϫ�¾��M�۹�O�@�줣²�檺�H���C��x�I�O�ʤs�C���x��\n"
		"�h�E���������q�̡M���O�L���H���Q������M�S�n��B�͡M���@���|�\\\n"
		"�X�Z�L���k�̪��[�l�C\n" );

	set("attitude", "friendly");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 2);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_skill("celestial", 100);
	set_skill("celestrike", 100);
	set_skill("pyrobat-steps", 100);
	set_skill("six-chaos-sword", 100);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("sword", "six-chaos-sword");
	map_skill("dodge", "pyrobat-steps");

	setup();

	carry_object(__DIR__"soulimpaler")->wield();
}

