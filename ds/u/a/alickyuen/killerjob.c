#include <ansi.h>

inherit NPC;

string *past = ({ });
string *now = ({ });
string *future = ({ });
string *dream = ({ });

void load();

void create()
{
	set_name(HIW"時空追捕員"NOR, ({ "epoch catcher", "catcher" }) );
	set("level", 50);
	set("long", @long
在你眼前的是一位裝束古怪的人，身上穿著、帶著很怪異的東西，不
像這個時空的人。
突然他狠狠的望過來，你嚇得不敢再望。
long);
	setup();
}

void init()
{
	add_action("do_go", "go");
	add_action("do_go", "north");
}

int do_go(string arg)
{
	if( !arg ) return notify_fail("where you want to go?\n");

	command("say i won't let you go .");

	return 1;
}
