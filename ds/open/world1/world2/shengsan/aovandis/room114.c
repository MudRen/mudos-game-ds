// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
美麗的花朵和植物在走到的兩旁，每三五步就有一棵長直的大樹。亮
麗的陽光照射在油亮的綠色植物上。安靜的植物園是全市最漂亮的公園，
市民們都利用閒暇之餘來這裡散散步，溜溜鳥，賞賞花，放鬆一下緊繃的
情緒。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room112",
            "east" : __DIR__"room115",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bug0.c" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

