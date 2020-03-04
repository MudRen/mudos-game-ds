// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡雜草叢生，並沒有做什麼開發。你看見旁邊的雜草裡似乎有
些白色的東西，還有點腐臭味。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out012",
	    "east" : __DIR__"out064",
            ]));
	set("item_desc",([	
	"白骨" : "雜草裡有一堆獸骨，從形狀看起來應該是一隻小狗的屍骨。\n",
	])	);
	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}