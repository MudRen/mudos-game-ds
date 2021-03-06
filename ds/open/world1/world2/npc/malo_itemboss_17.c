#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("道具店老闆" , ({ "shop boss","boss" }));
	set("long",@LONG
  這個留著一把山羊鬍的男人就是這一家道具店的老闆，很開朗的對
  著你微笑。
	==========================
	商品清單	list
	購買商品	buy <商品>
	==========================
LONG);
	set("race","human");
	set("gender","男性");

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
	add_money("dollar", 570);		//帶的錢(coin古代,dollar現代,未來沒有)
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

