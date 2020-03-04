#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("���]�d�i�p�j" , ({ "hotel employee","employee" }));
	set("long",@LONG
  �L�O�o�@�a�������p�G�A�L�������������U�ȤH�C
	==========================
	�q�Х�	checkin
	�ӫ~�M��	list
	�ʶR�ӫ~	buy <�ӫ~>
	==========================
LONG);
	set("race","human");
	set("gender","�k��");
	set("inquiry",([
  "rest" : "�𮧤@���u�n200����A�u�n�q��(check in)�N�i�H�𮧤F�I\n",
  "check in" : "�@��200��ж��H�z�D��I\n",
]));
	set("sell_list",([
  "/open/always/newspaper" : 10,
  "/open/always/torch" : 10,
]));
	set("level",12);
	set("no_fight",1);
	setup();
	add_money("dollar", 370);		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
}

void init()
{
	object ob=this_player();
	::init();
	if( userp(ob) && this_object()->visible(ob) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_check","checkin");
	return;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command("say �w����{!!");
			break;
		case 1:
			command("smile");
			break;
	}
	return;
}

int do_check(string arg) // rest & sleep
{
	object me,ob;
	string c;
	me = this_player();
	ob = this_object();

	if( arg )
		return 0;
	if( !me->can_afford(200) ) return notify_fail("�A���W���������C(200)\n");
	if( me->query_temp("malo/inn")) return notify_fail("�A�w�g�q�L�ФF�A�Цۦ�h�ж��𮧡C\n");
	me->set_temp("malo/inn",1);
	me->receive_money(-200);
	message_vision("$N�I���F$n�q�Ъ���ʤ��C\n",me,ob);
	command("say ���±z���f�U�A�бz�ۦ��ܩж��𮧧a�C");
	return 1;
}
