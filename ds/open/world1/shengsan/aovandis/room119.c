// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
有種清爽的香味往你身上撲了過來，周圍有好多奇花異草及各種的可
愛小昆蟲。你正是在奧凡迪斯著名的植物園裡。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room117",
	    "west" : __DIR__"room118",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

