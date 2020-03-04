// Room: /u/s/slency/area/ugelan/wood5.c

inherit ROOM;

void create()
{
	set("short", "森林深處");
	set("long", @LONG
這裡較其他地方稍微亮了一些，有些許的陽光從葉片縫隙中穿了過
來，這裡的樹木上有很名顯的打鬥痕跡，看起來應該是刀劍等兵器所造
成的，依照痕跡的新舊看來，這裡所發生的戰鬥想來有不少次了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood6",
  "east" : __DIR__"wood4",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
