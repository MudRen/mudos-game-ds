/**
 * Shadow's area [湖底世界 - 淺灘 - a4]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"淺灘"NOR);
	set("long",@LONG
腳下的地在此處往下開始延伸，似乎看不到可以通往何處。之前
隨處可見的魚蝦全都消失了，附近則聳立著一座巨大，長滿綠色苔蘚
的洞穴(cave)，稍遠處有個地方似乎可以潛入水底(dive)。
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([
		"west" : __DIR__"a3",
		"south" : __DIR__"a2",
	]));
	set("item_desc",(["cave" : "裡頭一片漆黑，什麼也看不到，你想對裡頭大吼一聲試試看，或許\會有人聽到(shout 有人在嗎)。\n"]));
	
	setup();
}

void init()
{
	add_action("do_dive", "dive");
}

int do_dive()
{
	object me = this_player();
  message_vision("$N"NOR"深深地吸了一口氣，然後潛入海底。\n", me);
  me->start_busy(1);
  me->move(__DIR__"a5");
	return 1;	
}
