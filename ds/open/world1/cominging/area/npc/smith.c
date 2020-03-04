inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("�K�K", ({ "smith" }) );
	set("long","�o�O�B�F�����K�K�A\n"
		"�A�i�H�ݰݥL���椰��F��(list),�άO�V�L�ʶR�U�ت��~(buy)\n");
	set("no_fight",1);
	set("chat_chance", 1);
	set("chat_msg", ({
  "�K�K��: �̪�ͷN�u�O�����A�u�Q��ӤH���������@��\n",
  "�K�K�ΤO�����K���W�V���C\n"
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
