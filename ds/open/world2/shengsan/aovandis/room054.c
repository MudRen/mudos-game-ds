// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"學術走道"NOR);
	set("long", @LONG
你站在一條有學術氣息的走道上。往上走你可以到達美達崙大學的入
口。你可以看到一個牌子(sign)矗立在入口處。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room053",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("item_desc", (["sign":@NOTE

		     �翦�����      ﹏
	    ﹏       │ 內 │
	             │ 部 │            ﹏
	﹏         �翦� 整 �澺�
		﹏ ││ 修 ││
		   ││ 中 ││﹏
		   │�檛����謖x
		 ╭┴╮    ╭┴╮   ﹏
	     ﹋﹌��─��﹋﹌��─��﹋﹌
	         ﹌       ﹏    ﹌      ﹏
NOTE
        ]) );

	setup();
	replace_program(ROOM);
}