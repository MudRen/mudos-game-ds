// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	string *order = ({"�l", "��", "�G", "�f", "��", "�x", "��", "��", "��", "��", "��", "��"});

	set_name( (order[random(12)]) + "������", ({ "hell guard", "guard" }) );
	set("long", "�o�O�@��Ӧ۳��ɪ��u�@���M�M������@�k���d�C\n");
	set("attitude", "friendly");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);

	set("str", 40);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 100000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "�ܹD�R�^�١T�H�ڭu���q���f�a�C\n"
	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);

	setup();

	carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/steel_fork")->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIB + name() + "���D�R���N�^�k�D�l��M�{�b�w�g�����@�k���ȡM�N���i��T\n\n"
		+ name() + "�����εo�X�շt���ť��M�H�J�a�U�����F�C\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIB "�@�D�ť��q�a���ɰ_�M�ť����X�{�@�Ӥ�����e�B���زu�񪺰���C\n\n"
		+ name() + "���D�R���N�^�k�D�l��M�S���@�k�T\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}