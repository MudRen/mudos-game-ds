// Modify with AreaMaker1.0
// Room28.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一片人煙稀少的樹林裡。西邊和南邊都有樹擋住了你的
去路，東北方刮來一陣陣的大風，狂風呼呼的吹著，彷彿整個樹林都
在搖晃一般。
LONG
	);
	set("exits", ([
		"north": __DIR__"room18",
		"east": __DIR__"room29",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

