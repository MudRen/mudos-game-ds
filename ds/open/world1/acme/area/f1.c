// Room: /open/world1/acme/area/f1.c

inherit ROOM;

void create()
{
	set("short", "小徑");
	set("long", @LONG
你正走在這幽幽長徑中，蜿蜒曲折的小徑因人煙罕至，小徑上長
滿了野菅芒，在這野草堆不時傳出昆蟲的鳴叫聲，配合著枝頭上的野
鳥譜出如黃鶯出谷之動人樂章。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f2",
  "southeast" : __DIR__"pass5",
]));
     set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
