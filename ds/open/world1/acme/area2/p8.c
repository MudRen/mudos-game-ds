// Room: /u/a/acme/area2/p8.c

inherit ROOM;

void create()
{
	set("short", "池邊小徑");
	set("long", @LONG
你正走在小池旁的小徑中，你可望見池中紅鯉悠閒的游著，池中荷花
盛開，從荷葉不時傳來青蛙「呱∼呱∼」的叫聲，往北望去可看見一間小
屋，西邊則有一座拱橋。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"p7",
     "north": __DIR__"start",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
