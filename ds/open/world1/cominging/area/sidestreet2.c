inherit ROOM;
void create()
{
	set("short", "側街中");
	set("long",@LONG
這裡還是隱隱的聽得到西邊的那一戶人家在吵鬧，你彷彿看到有許
多的人跑了出來看戲，不過由於門是關著的，所以都看不到什麼東東，
西邊是側街的轉角，而往東邊則是往步靈城的南邊的街道上，你覺得這
裡的街道上有一點髒。
LONG
	);
	set("exits", ([
  "west" : __DIR__"sidestreet1.c",
  "east" : __DIR__"sidestreet3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
