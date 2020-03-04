// Room: /u/m/mulder/area/shop5.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "新彼得城 - 休息室");
	set("long", @LONG
你看來有點疲勞，不如在這�媟略@下吧．或是在這�媯市搕@
下與你失散的朋友．或是你是來打混的？？
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road9",
]));
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_fight",1);
	set("light", 1);
	setup();
}
void init()
{
	add_action("do_rest","rest");
}
	int do_rest(string arg)
{
	object me;
	me=this_player();
	if(!arg) return notify_fail("你已經充滿能量?\n");
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
	me->reincarnate();
	message_vision( HIG"你感覺有一種力量存入你身體\n", me);
	tell_object(me,"你的身體狀況完全回復了。\n");
	return 1;
	} else return notify_fail( HIR"你沒有受傷, 只覺得心情平靜了許\多。\n");
return 0;
}


	


