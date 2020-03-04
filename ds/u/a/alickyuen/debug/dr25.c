// Room: /u/a/alickyuen/area/dr25.c
// 改long and exits
inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Computer-room");
	set("long", @LONG
這間電腦室多人的是，一堆堆人在排隊，想進內上學習班，但現在剛好
電腦室增添了一些新設備而重新開放，所以你看到有一些人不耐煩地走了，
但仍有一些人死心不息，希望進內。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dr16",
"enter" : __DIR__"dr26", //加出口
]));
set("objects", ([
__DIR__"npc/wnurse" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
