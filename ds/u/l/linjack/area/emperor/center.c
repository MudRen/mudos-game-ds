#include <room.h>
inherit ROOM;
void create()
{
 set("short","廣場");
 set("long",@LONG
這裡是叉路上的小廣場, 聚集了不少人, 也因此這邊擁有
十分大量的攤販和店面, 如果你有什麼物資缺乏, 可以儘管到
這邊採購.
LONG
    );
 set("exits",([ "south":__DIR__"market2",
                "north":__DIR__"market1",
                "west":__DIR__"market3",
                "east":__DIR__"road6",
                "southeast":__DIR__"road2_1"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}