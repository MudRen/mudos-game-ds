inherit ROOM;
void create()
{
	set("short", "步靈城西大街");
	set("long",@LONG
你一走到這感覺這裡很無聊的樣子，什麼東西都沒有，偶爾幾個馬
車跑了過去，和一些些的人們經過，顯得有些無聊，不過這裡很空曠，
很適合做一些大型的活動，歷年來的許多大活動都在這舉行或者是在中
央廣場。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest3.c",
  "west" : __DIR__"bwest5.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
