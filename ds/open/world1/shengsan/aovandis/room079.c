// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"旅社"NOR);
	set("long", @LONG
你在一間旅社裡，這是全城中服務最好且設備最完善的旅社，出外旅
行的人一定都會投宿在這裡補充一日所消耗的精力。櫃臺小姐親切的笑容
讓你會感覺到賓至如歸的感覺。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room068",
	    "up"   : __DIR__"room104",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}