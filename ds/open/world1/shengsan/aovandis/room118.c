// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
絡繹不絕的遊客在這觀賞這裡的一草一木，不時你會看到孩童的嬉鬧
聲穿梭期間，有種清爽的香味往你身上撲了過來，周圍有好多奇花異草及
各種的可愛小昆蟲。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room116",
            "east" : __DIR__"room119",
	    "west" : __DIR__"room113",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

