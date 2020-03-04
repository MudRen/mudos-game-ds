#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("���Y�p�c",({ "street seller","seller","street","�p�c" }));
	set("long",
		"�o�O�M���b��D�W�c�檫�~���p�c�A�L�i�঳�̷s���F��C\n"
		"�A�i�H�V�L�߰ݩ|�L�s�f(list)���ʶR(buy)�C\n");
	set("level", 5);
	set("age",10);

	set("no_fight",1);

	set("chat_chance", 8);
	set("chat_msg", ({
  "���Y�p�c�j�n����: �ӳ�ӳ�,����j�S�� ��C\n",
  "���Y�p�c�b�V���H���Щҽ檺���~�C\n",
}));
	set("sell_list",([
  ALWAYS+"torch": 6,
  __DIR__"obj/orange": 20,
]));
	setup();
	add_money("coin",150);
}
void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}
