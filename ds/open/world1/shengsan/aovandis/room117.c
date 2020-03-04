// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"植物園"NOR);
	set("long", @LONG
安靜的植物園是全市最漂亮的公園，市民們都利用閒暇之餘來這裡散散
步，溜溜鳥，賞賞花，放鬆一下緊繃的情緒。很多時候也會有市民站在肥皂
箱上高談拓論起來，以抒發己見。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"room119",
	    "west" : __DIR__"room116",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

