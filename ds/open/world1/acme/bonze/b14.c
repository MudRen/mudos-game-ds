// Room: /open/world1/acme/bonze/b14.c

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
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"b15",
  "west" : __DIR__"b17",
  "north" : __DIR__"b16",
  "south" : __DIR__"b13",
]));
set("objects",([
   __DIR__"npc/bonze" : 1,
   __DIR__"npc/bonze2" : 1,
]) );
        set("light",1);

	setup();
	replace_program(ROOM);
}
