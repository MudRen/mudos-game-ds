inherit ROOM;
void create()
{
	set("short", "步靈城西大街");
	set("long",@LONG
你站在步靈城西邊的西大街的街上，路上有些人向你販售二手物品
，不過看起來卻不怎麼的好，東邊是步靈城的中心，有些燈光從那兒傳
了過來。
LONG
	);
	set("exits", ([
  "east" : __DIR__"boo-lin.c",
  "west" : __DIR__"bwest1.c",
]));
	set("objects",([
  __DIR__"npc/adventurer.c" :1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
	replace_program(ROOM);
}
