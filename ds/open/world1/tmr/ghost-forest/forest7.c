// Room: /open/world1/tmr/ghost-forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "幽徑");
	set("long", @LONG
你正走在林中一條幽徑，你只覺得小徑兩旁的樹木了無生氣，整座林
間充塞著一股鬱悶潮溼之氣，令人不寒而慄，真想快點趕路，早一分離開
這種鬼地方。
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"forest5",
  "northwest" : __DIR__"forest9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
