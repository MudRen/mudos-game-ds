#include <room.h>
inherit ROOM;
void create()
{
 set("short","往山腰的路上");
 set("long",@LONG
往前放眼望去, 盡是一片蒼翠的森林, 這邊還能看到幾個江湖
過客, 但是你感到森林中似乎就沒有什麼人在走動了. 仔細往遠方
望, 山頂上邊有一個建築物.
LONG
    );
 set("exits",([ "east":__DIR__"mountdown3",
                "northwest":__DIR__"mountdown1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}