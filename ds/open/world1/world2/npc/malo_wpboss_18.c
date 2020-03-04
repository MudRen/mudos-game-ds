#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("�Z��������" , ({ "shop boss","boss" }));
	set("long",@LONG
  �L�J��î���O�@�Ӻ����j�������K���B�A�������β�l�W����y��
  �ۦ��A�ݤf�٦��@�ǵJ���C
	==========================
	�Z���M��	list
	�ʶR�Z��	buy <�Z��>
	�եΪZ��	try <�Z��>
	==========================
LONG);
	set("race","human");
	set("gender","�k��");

	set("sell_list",([
  __DIR__"../wp/wood_axe_5" : 5,
  __DIR__"../wp/wood_blade_5" : 5,
  __DIR__"../wp/wood_dagger_5" : 5,
  __DIR__"../wp/wood_fist_5" : 5,
  __DIR__"../wp/wood_fork_5" : 5,
  __DIR__"../wp/wood_hammer_5" : 5,
  __DIR__"../wp/wood_staff_5" : 5,
  __DIR__"../wp/wood_sword_5" : 5,
  __DIR__"../wp/wood_whip_5" : 5,
  __DIR__"../wp/iron_axe_10" : 10,
  __DIR__"../wp/iron_blade_10" : 10,
  __DIR__"../wp/iron_dagger_10" : 10,
  __DIR__"../wp/iron_fist_10" : 10,
  __DIR__"../wp/iron_fork_10" : 10,
  __DIR__"../wp/iron_hammer_10" : 10,
  __DIR__"../wp/iron_staff_10" : 10,
  __DIR__"../wp/iron_sword_10" : 10,
  __DIR__"../wp/skin_whip_10" : 10,
  __DIR__"../wp/rock_throw_10" : 2,
]));
	set("age",37);
	set("level",18);
	set("no_fight",1);
	setup();
	add_money("dollar", 270);		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/leather_gloves_5")->wear();
//	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_hat_4")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_try","try");
}

