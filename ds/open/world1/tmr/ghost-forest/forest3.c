// Room: /u/t/tmr/area2/forest3.c

inherit ROOM;

void create()
{
	set("short", "幽徑");
	set("long", @LONG
這是一條森林中的幽徑，尤其四周林木參天，高聳入雲，盡遮光線，
顯得四周陰暗之極，於白晝行走，仍如黑夜般伸手不見，兼之四週陰森
寒冷，似有鬼魅妖魔居伏，膽子稍小之人恐怕已呼天喊地了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"forest5",
  "southwest" : __DIR__"forest2",
]));
          set("outdoors","forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
