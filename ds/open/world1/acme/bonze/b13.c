// Room: /open/world1/acme/bonze/b13.c

inherit ROOM;

void create()
{
	set("short", "凌雲寺內");
	set("long", @LONG
這條通道是由石塊所構成，石塊與石塊中的縫隙中有一些小草長
出來，兩側的盆栽跟花木長的很茂盛，看來受到很好的照顧。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"b14",
  "south" : __DIR__"b12",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
