/* �����Ѫ�(Mercer) */
#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name(HIG"�楬���ӤH"NOR, ({ "mercer" }) );
	set("long",@LONG
�o�O�@�ӽ�f����o�ܰ��������ӡA
�A�i�H��(list)�V�L�M�ݦ����ǥ��i�R(buy)�C
LONG
	);
	set("no_fight",1);
	set("chat_chance", 1);
	set("chat_msg", ({
  (: command,"bow" :),
}));
	set("sell_list",([
  __DIR__"obj/cloth.c":3,
  __DIR__"obj/cloth1.c": 4,
  __DIR__"obj/cloth2.c": 5,
  __DIR__"obj/cloth3.c": 3,
  __DIR__"obj/cloth4.c": 4,
  __DIR__"obj/cloth5.c": 4,
  __DIR__"obj/cloth6.c": 4,
]));
	setup();
	add_money("coin",50);
}

void init()
{
	::init(); //�ѤF�[.. @#$%^.. Luky
	add_action("do_buy","buy");
	add_action("do_list","list");
}