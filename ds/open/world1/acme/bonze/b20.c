// Room: /open/world1/acme/bonze/b20.c

inherit ROOM;

void create()
{
	set("short", "梯田");
	set("long", @LONG
這個梯田所種的稻米是供給「凌雲寺」和尚所食用的，「凌雲寺
」的大大小小都是靠這個梯田過日子的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b11",
]));
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
