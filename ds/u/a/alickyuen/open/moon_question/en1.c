#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "花燈大會");
	set("long", @long
這裡正是一年一度的中秋節的花燈大會的舉行場地的正門，門旁
種滿了很多美艷的鮮花，還掛上了不少七彩繽紛的花燈，場面盛況空
前，一堆人在這站著觀賞，你已被擠得喘不過氣來。
long);
	set("exits", ([
		"east" : "/open/world1/tmr/area/hotel",
		"west" : __DIR__"en2",
	]));
	set("light", 1);
	set("no_recall", 1);

	setup();
}
