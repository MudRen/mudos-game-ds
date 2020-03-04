// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�����x�L", ({ "town garrison", "garrison" }) );
	set("long",
		"�o�O�ӥ��b���椽�Ȫ������x�L�M���M�M�\\�h�Z�L�H����_�ӡM�x�L\n"
		"�̪��Z�\\��b�}�P���`�M���O�L�̬O����´�B�����ߪ��Ԥh�M�֤]��\n"
		"�����a�۷S�L�̡C\n");

	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("pursuer", 1);

	set("str", 27);
	set("cor", 26);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"�����x�L�ܹD�R�٤��֩�U�Z������N���S\n",
		"�����x�L�ܹD�R�j�x�N�������ڮ��S�ϤF�T�ϤF�T\n"
	}) );

	set_skill("unarmed", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 100);

	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 70);
	set_temp("apply/move", 100);

	setup();

	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}

