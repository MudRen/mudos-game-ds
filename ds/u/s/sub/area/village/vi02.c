// Room: /u/s/sub/area/village/vi02.c

inherit ROOM;

void create()
{
	set("short", "小徑");
	set("long", @LONG
路旁長滿了一棵棵的松樹，看起來至少在這裡聳立了好幾十年了。茂
盛的枝葉將天空遮掩了大半邊，讓這裡四季都相當地陰涼，偶而聽到的鳥
叫聲更突顯這裡的寂靜。東邊有一座小山丘，小徑向西南方延伸。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"vi01",
  "eastup" : __DIR__"vi03",
]));

	setup();
	replace_program(ROOM);
}
