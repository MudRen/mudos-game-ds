// 奧凡迪斯
// LV 1~50
// 解迷地點
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"服飾精品店倉庫"NOR);
	set("long", @LONG
好多好多的衣服飾品擺放在這邊，一位店員正在這裡認真地清點服飾
。這裡的光線並不怎麼充足，有點暗暗的，而且你踏在地板的感覺好像底
下是空空的。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room095",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

