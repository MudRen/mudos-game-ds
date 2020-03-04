// chiplady.c			Shengsan@DS	1999.4.4
// 籌碼小姐

#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";

int to_say_chip();

void create()
{
	set_name("蜜兒",({ "mill","chip lady","lady" }));
        set("level",9);
	set("title","籌碼小姐");
	set("race", "人類");
	set("gender","女性");
	set("age", 19);
	set("long",
@LONG
可愛美麗的小姐, 你可以拿錢跟她換籌碼. ( ask mill about chip )
LONG
        );
	set("attitude", "friendly");

	set("inquiry",([
           "籌碼": (: to_say_chip :),
           "chip": (: to_say_chip :),
	]));
        setup();
        seteuid(getuid());
}

void init()
{
	add_action("do_change","change");
}


int do_change(string schip)
{
	object me;
	int chip;
	me = this_player();

	if(!schip)
	{
		command("think");
		command("say "+me->query("name")+"，你要幾枚籌碼啊？");
		return 1;
	}
	if(sscanf(schip,"%d",chip)!=1)
	{
		command("?");
		command("say "+me->query("name")+"，你要幹嘛啊？");
		return 1;
	}
	if(me->can_afford(chip*10)==0)
	{
		command("say "+me->query("name")+"，你似乎沒有那麼多錢來買籌碼？");
		return 1;
	}

	me->receive_money(chip*(-10));
	Game_receive_chip(chip,me);

	message_vision("$N拿出"+F_VENDOR->price_string(chip*10,me->money_type())+"給"+query("name")+"。\n",me);
	command("smile");
	command("say "+me->query("name")+"，這些是你要的籌碼。");
	return 1;
}


int to_say_chip()
{
	object me = this_player();
write(@HELP

        指  令                         說    明
=====================================================================
	change <籌碼數>		用身上的錢來兌換籌碼
=====================================================================

HELP);
	command("say 目前是"+F_VENDOR->price_string(10,me->money_type())+"換一枚籌碼。");
	return 1;
}
