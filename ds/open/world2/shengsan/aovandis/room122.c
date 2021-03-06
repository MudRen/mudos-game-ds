// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"市立圖書館"NOR);
	set("long", @LONG
這裡藏有豐富的圖書，你看到右面牆邊有一排電腦(computer)，似乎
可以透過電腦查詢你要的圖書。現代化的圖書查詢的確讓你省下不少的時
間。牆上有個告示牌(note)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north": __DIR__"room121",
	]));

	set("objects", ([
		__DIR__"npc/obj/pc_lib":1,
	]));

	set("item_desc", (["note":@NOTE
佈告牌上寫著:

	你可以利用電腦(computer)查詢圖書，如果確定要某本圖書
	電腦也會以最快的速度為您取出你要的書籍。

NOTE
        ]) );

	set("no_clean_up", 0);
	set("no_recall",1);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}