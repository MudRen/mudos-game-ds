// 山貓(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一條條石鋪成的小路上，小路的北面就是比武場的中看台，南面是
比武場的大門。
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"gate",
		"north":__DIR__"kantai",
	]));
	setup();
}