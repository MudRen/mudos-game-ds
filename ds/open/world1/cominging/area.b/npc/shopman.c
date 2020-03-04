#include <path.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
	set_name("商人", ({ "shop man", "man", "shop" }) );
	set("long",
		"他是旅居各地的商人。\n"
		"你可以問問他有賣什麼東西(list),或是向他購買各種物品(buy)\n"
		",抑或是向他出賣東西(sell)\n"
	);
	set("level", 10);
	set("no_fight",1);
	set("age", 50);
	set("chat_chance", 1);
	set("chat_msg", ({
	"商人對你說：來喔來喔∼快來買喔。\n",
	}) );
	set("storeroom", COMINGING_PAST+"area/shop.c");
	setup();
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
	add_action("do_sell","sell");
}