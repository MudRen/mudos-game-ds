// gebi5.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","西域大戈壁");
       set("long", @LONG
這是西域的大戈壁，要走出這裡並非易事。不遠處塵土沙粒鋪天蓋
地般吹來，看來要起風暴了。
LONG);
        set("exits", ([
                "east" : __DIR__"gebi4",
                "southwest" : __DIR__"road1",
        ]));
        set("outdoors", "land");
        setup();
}

