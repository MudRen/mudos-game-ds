// Room: /u/f/fanny/area/forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "草亭");
	set("long", @LONG
草亭裡只有簡單的桌椅，上面還佈滿了灰塵，看來這裡似乎人煙
罕至，的確是個休息的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"forest7",
]));

	setup();
	replace_program(ROOM);
}
