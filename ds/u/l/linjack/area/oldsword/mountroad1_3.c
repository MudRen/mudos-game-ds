#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林中");
 set("long",@LONG
這邊要比剛才那邊還幽暗一些, 不過白晝時你仍然可能清楚
的看見四周的景物, 你明白這邊不會有什麼危險的. 往東走可以
更深入進去, 但是路已經漸漸不明顯了.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad1_4",
                "southwest":__DIR__"mountroad1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
