inherit ROOM;
void create()
{
	set("short", "步靈城西大街");
	set("long",@LONG
這裡是西大街，你一走到了這裡就感覺到隱隱的吵架聲，原來是南
邊巷口中的某一戶人在吵架，不知到為什麼聲音會這麼的大聲，連這裡
都聽得到，在東北邊有一家藥店，不知生意好無，東邊是往中央廣場，
而西邊也則是往西大門。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest2.c",
  "west" : __DIR__"bwest4.c",
  "south" : __DIR__"sidestreet.c",
]));
	set("objects",([
  __DIR__"npc/woman" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
