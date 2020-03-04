// Room: /u/m/mulder/area/road9.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "新彼得城 - 廣場大街");
	set("long", @LONG
  只要你向南走就可到這城的訓練所，進行一連串的特訓．你
覺得這�埵釣ワ_怪．．．．．你覺得常常有東西好像看著你．但你
仔細看，發現原來這裡是沒有人。你看見這裡有幾枝電燈柱．
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road20",
  "west" : __DIR__"road8",
  "east" : __DIR__"shop5",
]));
	set("item_desc", ([
        "lamp post" : "一個十分奇怪的電燈柱, 或許\你可以敲打看。\n",
        "電燈柱" : "一個十分奇怪的電燈柱, 或許\你可以敲打看。\n",
        ]));
	set("light",1);
	set("outdoors", "road");
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_knock", "knock");
}
	int do_knock(string arg)
{
	object me;
	me=this_player();
	if (arg != "電燈柱" && arg !="lamp post" )
	return 0;

	else
	{
	message_vision(HIW"$N向電燈柱敲了幾下，發現多了一條路，突然有人把$P捉入去！\n"NOR,me);
	me->move(__DIR__"blackshop");
	tell_room(environment(me),me->query("name")+"向電燈柱敲了幾下，發現多了一條路，突然有人把$P捉入 去！\n",me);
	return 1;	}
}
