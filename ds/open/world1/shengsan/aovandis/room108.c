// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"餐\廳內"NOR);
	set("long", @LONG
室內的裝潢是屬於溫暖色調，讓你有種回家的感覺，一旁的鋼琴聲彈
奏著典雅及抒情的樂章，使你的情緒漸漸的變為祥和。桌上閃爍不定的蠟
燭燃燒著，花瓶內的花朵是清晨才採收的新鮮花朵。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room107",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

