
inherit ROOM;

void create()
{
	set("short", "西側走廊轉角");
	set("long", @LONG
你看到走廊轉角的地方擺放著一個既大又長的花瓶，花瓶上彩釉的花
紋非常的美麗。牆上窗戶的造型也別具特色，窗外的陽光造射到花瓶身上
，反射出耀眼的光芒。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room16",
	    "north": __DIR__"room18",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
