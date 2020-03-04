// Room: /u/a/alickyuen/area/dr21.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Sickroom");
	set("long", @LONG
這裡便是小童專用的病房，雖然他們都病了，但他們仍圍著圈子，拿
著玩具，一起玩耍，面露笑容，氣氛很好，好像把生病中的事情忘得一光
二淨。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr18",
]));
set("objects", ([
__DIR__"npc/hchild" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
