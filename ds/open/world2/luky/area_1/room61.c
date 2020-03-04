// Modify with AreaMaker1.0
// Room61.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","湖畔");
	set("long", @LONG
一來到了這裡，你馬上就被美麗的依莉莎湖深深的吸引住了。清
澈的湖面如鏡子一般印出天色，湖邊上偶而會見到天鵝悠游在其中。
你還看到地上有許多外表十分光滑的鵝卵石，真想帶回去當紀念。
LONG
	);
	set("exits", ([
		"east": __DIR__"room62",
		"west": SHENGSAN2"aovandis/out046",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

