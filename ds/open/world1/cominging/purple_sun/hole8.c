// 紫陽山頂端山洞內
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山洞中");
	set("long", @LONG
你現在走在山洞中，這裡跟剛剛不同的是，有幾個老人坐在一片石
壁的旁邊的小石凳上，每個人面色紅潤，不像是年紀已長的人，他們的
臉上的神色似乎不怎麼好，在你的腳下有許多小小塊的石頭，比周圍的
地方的還要多出許多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hole7.c",
  "south" : __DIR__"hole5.c",
  "east" : __DIR__"hole9.c",
]));
	set("item_desc", ([
  "石壁" : "一片很大的石壁，旁邊還有些小細縫，似乎看起來有什麼作用。\n",
]));
	set("objects", ([
  __DIR__"npc/oldman.c" :1,
  __DIR__"npc/oldman2.c" :1,
  __DIR__"npc/oldman3.c" :1,
  __DIR__"npc/oldman4.c" :1,
]));
	set("no_fight",1);
	set("no_cast",1);
	set("no_exert", 1);
	set("no_steal", 1);
	set("world", "past");
	set("no_clean_up", 0);
	set("light",1);

	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if( arg != "石壁" && arg != "stone" )
		return 0;
	if( !me->query_temp("open_stone_door") )
	{
		message_vision(HIW"$N使勁推動石壁，卻見石壁一動也不動。\n"NOR,me);
		return 1;
	}
	message_vision(HIW"$N使勁推動石壁，只見石壁旁煙霧一起，整個人都翻了過去。\n"NOR,me);
	me->move(__DIR__"4f_secret.c");
	tell_room(environment(me), "只見石壁一陣晃動，"+me->name()+"突然出現在這裡！\n", ({ me }));
	me->start_busy(1);
	if( me->query_temp("open_stone_door") > 0 ) me->add_temp("open_stone_door", -1);
	else me->delete_temp("open_stone_door");
	return 1;
}
