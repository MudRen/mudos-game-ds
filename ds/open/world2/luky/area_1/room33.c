// Modify with AreaMaker1.0
// Room33.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一片人煙稀少的樹林裡。到處都是高大的樹木，突然有
一陣風吹過來，你忍不住打了個噴嚏『哈∼∼啾！！』。
LONG
	);
	set("exits", ([
		"north": __DIR__"room23",
		"south": __DIR__"room43",
		"west": __DIR__"room32",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

