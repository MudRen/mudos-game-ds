// Room: /u/a/alickyuen/area/dr5.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Signplace");
	set("long", @LONG
這�堿O一樓的大堂的輪候處，你看見一隊一隊整齊的人龍正在排隊拿
籌，你可以在這拿籌後，前往醫院二樓的門診部看醫生治病。
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr4",
  "north" : __DIR__"dr6",
]));
set("objects", ([
__DIR__"npc/nurse" : 1,
]));
set("light",1);
set("world","future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
