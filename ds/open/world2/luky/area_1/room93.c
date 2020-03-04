// Modify with AreaMaker1.0
// Room93.c

inherit ROOM;

void create()
{
	set("short","湖畔");
	set("long", @LONG
你走到這裡一不小心了一跤。這裡四處都是泥濘，當然也少不了
人類的特產－垃圾  地上因為潮濕有點滑，你最好還是走慢一點吧。
LONG
	);
	set("exits", ([
		"north": __DIR__"room83",
		"east": __DIR__"room94",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

