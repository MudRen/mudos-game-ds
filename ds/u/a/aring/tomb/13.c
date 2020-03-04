// Room: /u/a/aring/tomb/12.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大墓園－墳墓");
        set("long", "你正站在一座墳墓的上頭，這裡猛然立了一個棺木，棺木裡面似
乎有些微的聲音傳出，膽子若夠大可以打開"YEL"棺木"NOR"來看看"HIR"(open)"NOR"。
");
        set("light", "0");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"14.c",
  "west" : __DIR__"12.c",
]));

        setup();
        replace_program(ROOM);
}

