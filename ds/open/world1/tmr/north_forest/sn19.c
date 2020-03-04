// Room: /u/l/lestia/area/sn19.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG
沿著小道走了過來，你發現原本筆直的小道開始彎曲狹小，似乎有許多
人走到這裡便回頭而去，原本被踏平的泥土開始變成雜草叢生的草地，你心
底開始懷疑，為什麼他們都只走到這裡而不繼續的往前走呢？
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn20",
  "south" : __DIR__"sn18",
]));
set("objects", ([ 
__DIR__"npc/wolf":2,
]));

	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
