
inherit ROOM;

void create()
{
	set("short", "西側走廊");
	set("long", @LONG
你看到桐紅色的牆壁上有一幅壁畫，上面畫的是一隻強壯的毒蛇攻擊
一團跳動的火球，你愈看愈是看不懂。沿著走廊的兩旁每隔一段距離
都有幾盆的盆栽擺放著。在你的西邊有一個廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "west"  : __DIR__"room28",
            "south" : __DIR__"room18",
	    "north" : __DIR__"room20",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
