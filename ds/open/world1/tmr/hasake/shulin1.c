// shulin1.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","山谷");
       set("long", @LONG
你走進山谷，這裡林木茂密，有如仙境。只見兩山之間流出一條小溪來，
清澈的溪水從你腳邊靜靜地淌過。口渴的你正好可以飲個飽。
LONG);
        set("exits", ([
                "southeast" : __DIR__"shulin",
        ]));
        set("outdoors", "land");
        setup();
}

