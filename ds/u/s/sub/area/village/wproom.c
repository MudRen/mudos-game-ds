// Room: /u/s/sub/area/village/wproom.c

inherit ROOM;

void create()
{
	set("short", "五金行");
	set("long", @LONG
這裡是一間五金行，各種武器整整齊齊地掛在牆上。唐先生更是享譽
中外的老鐵匠。不少離開這裡出外打拼的人都還會特地回來跟唐先生購買
鐵器，讓唐先生的名聲更加的響亮。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"vi05",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_wpboss_20" : 1,
]));
	set("room_type", "sell");
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
