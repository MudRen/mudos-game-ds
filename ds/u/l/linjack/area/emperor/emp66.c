// Modify with AreaMaker1.0
// Room66.c

inherit ROOM;

void create()
{
	set("short","區域房間");
	set("long", @LONG
這個房間是由區域編輯器寫成，歡迎各位到夢幻七域(ds.muds.net 7000)
找作者藍藍的天打屁聊天，謝謝您的愛用。
LONG
	);
	set("exits", ([
		"north": __DIR__"emp56",
		"east": __DIR__"emp67",
		"west": __DIR__"emp65",
	]));
	setup();
	replace_program(ROOM);
}

