// Room: /u/a/alickyuen/area/gate4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠West"NOR);
	set("long", @LONG
這裡是Saint內的一條道路，四處的環境沒有什麼特別，而你又不清楚
一直去會通往那裡。但你看見很多人拿著一張二張的表格往那邊走去，看
起來那些是旅行團的參加表格。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst19",
  "east" : __DIR__"dst16.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
