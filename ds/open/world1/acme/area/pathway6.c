// Room: /u/a/acme/area/pathway6.c

inherit ROOM;

void create()
{
	set("short", "羊腸小徑");
	set("long", @LONG
這裡是一條小徑，往北邊可看見一間小屋，小徑二旁盡是雜草，小
徑中隱約可見一條血跡往北延伸，往南有一條小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"h",
  "south" : __DIR__"pathway5",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
