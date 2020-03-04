
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "後花園");
	set("long", @LONG
許多漂亮的小昆蟲在花叢間穿梭起舞，你正走在花園的走道之上，你
發現這裡的植物有點的怪異。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room30",
	    "north": __DIR__"room33",
            ]));

   set("objects",([
   PUDON"npc/sweeper":1,
   ]));
	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
