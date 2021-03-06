// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡迪斯正城門"NOR);
	set("long", @LONG
這裡是奧凡迪斯的正城門，城門及城牆都高得不太像話，看起來已經
沒有任何武器能對這裡造成破壞了，走道及兩旁上鑲著各種炫麗的琉璃，
所排出的圖騰樣式讓人匪夷所思。在城門旁你看到了一塊扁牌(plaque)。
如果你要出城(out)，別忘了跟守衛打招呼喔。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "north": __DIR__"room008",
	    "out":  "/open/world2/mainland1/map_23_27",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	set("item_desc", ([
		"plaque":@NOTE
扁牌上寫著:
		[1;32;44m�歈���������������������������������������[m
		[1;32;44m��      奧      凡      迪      斯      ��[m
		[1;32;44m�裺���������������������������������������[m

NOTE
     ]) );

	setup();
	replace_program(ROOM);
}
