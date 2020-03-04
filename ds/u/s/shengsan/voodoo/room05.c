inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是一個相當大的廣場，廣場的四周還是竹林分布著，但是這裡
可以聽到有人在練習武藝的聲音，其聲音氣勢和內勁，讓你不敢對他們有
所輕忽。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "east" : __DIR__"room04",
            "west" : __DIR__"room07",
	    "north": __DIR__"room06",
            ]));

        set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/snake" : 2,
            ]));
	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
