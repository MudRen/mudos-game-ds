#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�p��",({ "thief" }));
	set("long","�@�ӱ`�b�I�v���Ѫ��H�C\n");
	set("race","�H��");
	set("age",32);
	set("level",6 );
	set("chat_chance",10);
	set("chat_msg",({
  HIR"�p�����������Y�B����....\n"NOR,
  (: command,"hehe" :),
  (: random_move :),
}));
	set_skill("dodge",30);
	set_skill("unarmed",30);
	setup();
	add_money("coin",100);
}