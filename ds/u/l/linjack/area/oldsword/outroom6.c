#include <room.h>
inherit ROOM;
void create()
{
 set("short","湖中走道");
 set("long",@LONG
你來到了一條湖中走道, 左右兩旁各有一個小池塘. 蠻深的,
有些魚在裡面游著. 走道上還是有些守衛, 你仔細看了一下四周
的地理, 發現向雲堂四周的河溝的水是以此為主要的集合地.
LONG
    );
 set("exits",([ "north":__DIR__"outroom4",
                "south":__DIR__"outdoor1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
