inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("鐵匠", ({ "smith" }) );
	set("long","這是步靈城的鐵匠，\n"
		"你可以問問他有賣什麼東西(list),或是向他購買各種物品(buy)\n");
	set("no_fight",1);
	set("chat_chance", 1);
	set("chat_msg", ({
  "鐵匠說: 最近生意真是興隆，真想找個人來幫忙做一做\n",
  "鐵匠用力的往鐵塊上敲打。\n"
}));
	set("sell_list",([
  __DIR__"wp/axe.c": 10,
  __DIR__"wp/longsword.c": 15,
  __DIR__"wp/dagger.c": 10,
]));
	setup();
	add_money("coin",50);
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}
