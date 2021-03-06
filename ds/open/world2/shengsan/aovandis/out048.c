// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊");
	set("long", @LONG
地上的綠草茵茵，情人椅上的戀人含情脈脈，湖邊的風景迷昏了數對
男男女女。你還可以看到一些小孩在湖岸邊嬉戲玩耍，一副天真無邪的模
樣，讓你想起小時候的點點滴滴。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out049",
	    "west" : __DIR__"out047",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}