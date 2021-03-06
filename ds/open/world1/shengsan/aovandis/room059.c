// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"城主辦公室"NOR);
	set("long", @LONG
牆上精美的雕飾讓你下了一跳，一看就知道這裡不是一般人的辦公室
。原來這是奧凡迪斯城主的辦公地點。在他的辦公桌上可以看到很多公文
在上面，可見他平時是多麼的專於市政。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"room061",
	    "north": __DIR__"room017",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/mayor" : 1,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}