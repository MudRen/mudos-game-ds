// Room: /open/world1/dragoncity/northgate1.c

inherit ROOM;

void create()
{
	set("short", "玄武內門");
	set("long", @LONG
這裡是磐龍城的北城門的內城門，只見城門上方是三個大字。

[1;36m                      玄武門
[0m
近年來虎人族屢次侵犯磐龍城，故這兒把守相當嚴密，一些少帥
軍的官兵們正在盤查要離開磐龍城的人。兩邊是上城頭的石階，
向南進入城區。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"north1",
  "north" : __DIR__"northgate2",
  "northup" : __DIR__"walln1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
