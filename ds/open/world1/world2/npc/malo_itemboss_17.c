#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("�D�㩱����" , ({ "shop boss","boss" }));
	set("long",@LONG
  �o�ӯd�ۤ@��s���G���k�H�N�O�o�@�a�D�㩱������A�ܶ}�Ԫ���
  �ۧA�L���C
	==========================
	�ӫ~�M��	list
	�ʶR�ӫ~	buy <�ӫ~>
	==========================
LONG);
	set("race","human");
	set("gender","�k��");

	set("sell_list",([
  __DIR__"../obj/ginseng_potion" : 40,
  __DIR__"../obj/cow_potion" : 25,
  __DIR__"../obj/herb_potion" : 15,
  __DIR__"../obj/greentea" : 10,
  __DIR__"../obj/beer" : 10,
  __DIR__"../obj/travel_bag" : 15,
  "/open/always/torch" : 10,
]));
	set("age",41);
	set("level",17);
	set("no_fight",1);
	setup();
	add_money("dollar", 570);		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/leather_gloves_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_hat_4")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

