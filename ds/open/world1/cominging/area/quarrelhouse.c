/* 一家吵鬧的家(QuarrelHouse) */
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short","一間房舍");
	set("long",@LONG
這裡是一間房舍，你一進來就被一對夫妻所吵到，而且還禍從天降
的倒過來罵你，不過你倒是不願和他們吵，在這裡的空間很小，不過在
外面的三合院廣場就很大了，外面也有一些這裡的鄰居在看戲，不過現
在都在看你了！
LONG
	);
	set("exits",([
  "out" : __DIR__"sidestreet1.c",
]));
	set("light",1);
	set("no_clean_up",0);
	setup();
	create_door("out","門","enter",DOOR_CLOSED);
}
