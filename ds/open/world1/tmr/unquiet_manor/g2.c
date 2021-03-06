// Room: /open/world1/tmr/unquiet_manor/g1.c

inherit ROOM;

void create()
{
	set("short", "無寧之墳-墓道");
	set("long", @LONG
你正在走無寧莊園的地下墓道中，墓穴屍氣幾百年不曾流動，你
只吸入幾口就已覺得頭昏腦脹，只想要趕快離開這個地方。墓道中沒
沒有一絲光線，靜默的氣氛悄悄然帶來絕望的恐懼感。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g3",
  "south" : __DIR__"g1",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
