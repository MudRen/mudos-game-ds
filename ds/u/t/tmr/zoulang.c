// 山貓(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一條條石鋪成的小路上，小路的北面就是比武場的中看台，南面是
比武場的大門。你可以(enter)進入比武場。
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"gate",
	]));
	setup();
}

void init()
{
	add_action ("do_enter","enter");
}

int do_enter(string arg)
{
	object me=this_player();
	string mout=YEL ""+me->query("name")+"走進了比武場。\n" NOR;
	string min=YEL ""+me->query("name")+"場外走了進來。\n" NOR;

	message( "vision", mout, environment(me), ({me}) );
	me->move(__DIR__"kantai2");
	message( "vision", min, environment(me), ({me}) );
	return 1;
}
