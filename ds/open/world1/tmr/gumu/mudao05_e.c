// Room: /open/world1/tmr/gumu/mudao05_e.c

inherit ROOM;

void create()
{
        set("short", "墓道");
        set("long", @LONG
這里是古墓中的墓道，四周密不透風，借著�暀W昏暗的燈光，你能
勉強分辨出方向。�椄O用整塊的青石砌合起來的，接合得甚是完美，難
以從中找出一絲縫隙。燈光照在青石壁上，閃爍著碧幽幽的光點。
LONG
        );
        set("current_light", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao05",
  "east" : __DIR__"zhongting",
]));

        setup();
        replace_program(ROOM);
}

