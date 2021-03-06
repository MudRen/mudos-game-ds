#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("防具店老闆" , ({ "shop boss","boss" }));
	set("long",@LONG
  這裡坐著一位瘦小的男人，看他結實的兩臂便可知道這位老闆可不
  是一位簡單的人物。
	==========================
	防具清單	list
	購買防具	buy <防具>
	試穿防具	try <防具>
	==========================
LONG);
	set("race","human");
	set("gender","男性");

	set("sell_list",([
  __DIR__"../eq/cloth_clothes_5" : 5,
  __DIR__"../eq/cloth_clothes_f_5" : 5,
  __DIR__"../eq/cloth_clothes_7" : 5,
  __DIR__"../eq/cloth_gloves_3" : 5,
  __DIR__"../eq/leather_gloves_5" : 5,
  __DIR__"../eq/cloth_hat_4" : 5,
  __DIR__"../eq/cloth_hat_6" : 5,
  __DIR__"../eq/cloth_pants_5" : 5,
  __DIR__"../eq/cloth_pants_7" : 5,
  __DIR__"../eq/iron_armor_16" : 5,
  __DIR__"../eq/wood_armor_13" : 5,
  __DIR__"../eq/wood_armor_10" : 5,
  __DIR__"../eq/leather_boots_3" : 5,
  __DIR__"../eq/leather_boots_6" : 5,
  __DIR__"../eq/leather_boots_8" : 5,
  __DIR__"../eq/leather_boots_f_5" : 5,
]));
	set("age",35);
	set("level",17);
	set("no_fight",1);
	setup();
	add_money("dollar", 770);		//帶的錢(coin古代,dollar現代,未來沒有)
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
	add_action("do_try","try");
}

