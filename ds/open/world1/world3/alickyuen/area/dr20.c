// Room: /u/a/alickyuen/area/dr20.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Sickroom");
	set("long", @LONG
這裡是頭等病房，顧名思義是有錢人家才住得起的地方，你發現到身
邊的人都把你當成閒雜人，露出了一對非常恐怖的眼神，像想把你趕走似
的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dr19",
]));
set("objects", ([
__DIR__"npc/woman" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
