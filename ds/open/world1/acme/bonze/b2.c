// Room: /open/world1/acme/bonze/b2.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走進一處人煙罕至的山道中，四方左右都是長高及腰的雜草，
遮蔽了視線，草叢中彷彿有不知名的動物正匿居地觀察著你的行動，
四處無人，只聽見風吹草動的窸窸窣窣聲響。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"b3",
  "northwest" : __DIR__"b1",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
