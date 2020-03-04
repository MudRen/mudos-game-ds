// Room: /u/s/sonicct/area/shop6.c

inherit ROOM;

void create()
{
	set("short", "花園");
	set("long", @LONG
這裡種植的花十分漂亮，你真想摘下一朵花來送給你的愛人，可是你
的愛人是誰呢？在這裡的南面可以走出花園。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road16",
  "south" : __DIR__"road15",
]));
		 set("objects",([
  __DIR__"npc/butterfly":3,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
