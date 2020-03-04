
inherit ROOM;

void create()
{
	set("short", "東側走廊");
	set("long", @LONG
你看到桐紅色的牆壁上有幾扇的窗戶，從窗戶看出去可以看到外面的
景色。突然間在你的鼻子聞到了陣陣的香味。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"room11",
	    "north": __DIR__"room13",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
