// Room: /u/a/alickyuen/area/dr14.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Hall");
	set("long", @LONG
這�堳K是醫院的二樓，這�媊搣顗鬤E部，有什麼奇難雜症都可以找這
�娷憟苂慦v，但你必須先到留下一樓的登記處拿籌••。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dr13",
]));
set("objects", ([
__DIR__"npc/oldman" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
