// Room: /u/a/acme/area/cottage.c

inherit ROOM;

void create()
{
	set("short", "茅蘆");
     set("light",1);
	set("long", @LONG
這是一間用茅草所建造而成的小屋，中央放著用竹子所製成的方桌、
小椅，而牆上掛著二件簑衣和斗笠，屋內卻沒有窗子，使人覺得此地的人
家生活得定是十分的純樸。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"farm1",
]));
    set("objects",([
       __DIR__"npc/woman.c" : 1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
