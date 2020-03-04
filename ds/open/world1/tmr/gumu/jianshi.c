// Room: /d/gumu/jianshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"劍室"NOR);
	set("long", @LONG
一間擺滿兵器的石室，很多種劍都整齊地堆放在地上。周圍的火把
照的整個石室燈火通明，幾個古墓弟子正站在室中仔細挑選自己合手的
兵刃。�晲予騊菑@個木制的護具架，上面掛著些古墓弟子平時防身用的
護具。
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao07",
	]));

	setup();
	replace_program(ROOM);
}

