// garrison.c
#include <ansi.h>
inherit NPC;

void create()
{
	set("chat_chance", 4);
	set_name("宮門侍衛", ({ "palace guard","guard" }) );
	set("con", 19);
        set("age",30);
	set("str", 20);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set("long",
	"皇宮宮門守衛, 防止閒人進出皇宮\n"
	"他看起來雄壯高大, 相當難以應付的樣子。\n"
	);
        setup();	
	carry_object(__DIR__"wq/guardsword")->wield();
}

void init()
{
	add_action("do_guard", "go");
}

int do_guard(string arg)
{

	if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
	write( name() + "將你攔了下來。\n");
	command("say 這位旅客請止步, 皇宮禁地不準任意進出, 請你不要為難我。");

	return 1;
	}
