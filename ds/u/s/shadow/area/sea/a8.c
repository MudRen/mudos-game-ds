/**
 * Shadow's area [湖底世界 - 湖底通道盡頭 - a8]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

int push_time;

void create()
{
	set("short",HIC"湖底通道盡頭"NOR);
	set("long",@LONG
此處的水流晃動地非常厲害，通道的石壁彷彿隨時會倒塌下來一
樣。兩側的青色火焰也忽明忽滅，更增加了幾許恐怖的氣氛，一堵厚
實的石門佇立在你的面前，看來前方似乎已經沒有路可以前進...
LONG
	);
	set("light", 1);
	set("no_clean_up", 0);
	set("exits",([
		"west" : __DIR__"a7",
		"south" : __DIR__"a6",
	]));
	set("item_desc", (["石門" : "一扇厚重的石門，也許\可以試著推(push)看看。\n"]));

	setup();

}

void init()
{
	push_time = 0;
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me = this_player();
	
	if ( query("wasfound") )	return notify_fail("石門已經被人打開了！\n");
	
	if (arg != "石門")
		message_vision("沒有目標在推個甚麼勁呢？\n", me);
	else {
		push_time ++;
		if (push_time == 1)	{
			me->start_busy(1);
			message_vision("你把內力灌注於雙掌，使徑往石門一推...。\n石門文風不動。\n", me);
		}	else if (push_time == 2)	{
			me->start_busy(1);
			message_vision("你把內力灌注於雙掌，使徑往石門一推...。\n石門似乎移動了一些。\n", me);
		}	else if (push_time == 3)	{
			me->start_busy(1);
			message_vision("你把內力灌注於雙掌，使徑往石門一推...。\n石門慢慢地被$N推開了，露出一個可供人行的縫隙。\n", me);
		} else if (push_time == 4)	{
			me->start_busy(1);
			message_vision("你把內力灌注於雙掌，使徑往石門一推...。\n石門已經完全打開了！\n", me);
			set("exits",([
				"west" : __DIR__"a7",
				"south" : __DIR__"a6",
				"northeast" : __DIR__"a9",
			]));
			set("wasfound", 1);
		}
	}
	return 1;
}
