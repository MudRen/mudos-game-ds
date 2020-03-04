#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
這裡的空氣似乎清淨些，牆邊有一些床，被的生活用品，好像有
人在這邊生活仔細一看，一邊的牆上佈滿許多刻痕，可能是某些人為
了特種目的所準備的吧。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/waist-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

