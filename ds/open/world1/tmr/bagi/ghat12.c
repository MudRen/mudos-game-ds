// Room: /open/world1/tmr/bagi/ghat12.c

inherit ROOM;

void create()
{
	set("short", "林中小徑");
	set("long", @LONG
你正走在一條滿是雪堆的小徑上，小徑兩旁長滿了相互依偎的衫樹，大大
減低了高山上強烈的寒風，除了不停降下的片片雪花，似乎整個世界就是一片
寂靜。往西走不數十步遠可望見一處大崖壁。
LONG
	);
	set("outdoors", "snow");
	set("current_light", 3);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ghat11",
  "west" : __DIR__"ghat13",
]));

	setup();
	replace_program(ROOM);
}
