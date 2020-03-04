#include <path.h>

inherit ROOM;

void create()
{
        set("short", "凌雲峰－山裡頭");
        set("long", @LONG
你正走在一條頗為崎嶇難走的山路，道路兩旁長滿了鮮花，林間
一片詳和寧靜的氣氛，你可不時看到一些和尚過往。往南的方向是出
山的道路，往南則是更深入山裡頭。
LONG
        );
        set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "north" : __DIR__"hill4.c",
                "south" : __DIR__"hill2.c",
        ]));
        set("outdoors","forest");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


