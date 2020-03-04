inherit ROOM;
void create()
{
	set("short", "側街中");
	set("long",@LONG
這裡是一條小側街，在這一條側街上並沒有什麼東西，大多只是一
些房屋、建築罷了，而且在這裡的人煙也顯得較為大街上的安靜多了，
北邊是步靈城西大街，南邊是一條長長的側街。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bwest3.c",
  "south" : __DIR__"sidestreet1.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
