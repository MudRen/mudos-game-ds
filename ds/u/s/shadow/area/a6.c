/**
 * Shadow's area [荒廢漁村 - a6]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"浮橋"NOR);
	set("long",@LONG
這座浮橋是以羊皮氣囊為底再鋪上青竹建設而成，你小心翼翼地
踏上去，一路竹子摩擦發出的滋嘎聲讓你不得不放慢腳步，深怕一個
閃失就跌了下去。。你定了定心徐步前行，循向人影，找到了正佇立
在湖邊的一個年輕人，只見年輕人眉頭深鎖，深邃而空洞的雙眼正痴
痴地望著湖心。
LONG
	);
	set("light",1);
	set("outdoors", "land");
	set("exits",([
		"west": __DIR__"a4",
	]));
	set("objects",([
	__DIR__"npc/youngman":1,
	]));

	setup();

}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	if (arg != "down")	return 0;
	else {
		message_vision("$N往橋下跳下去！\n", me);
		me->move(__DIR__"sea/a1");
		return 1;
	}
}
