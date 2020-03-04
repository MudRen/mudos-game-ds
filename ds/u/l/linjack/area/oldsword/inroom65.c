#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這裡是正廳的北側, 由此可以通過一個走道是往後偏廳走的,
這邊有更多的護衛和弟子聚集, 因為後偏廳就是平常堂主所在的
地方, 當然不能讓閒雜人等進入, 要進去聽說要一張邀請函.
LONG
    );
 set("exits",(["north":__DIR__"inroom1",
                "west":__DIR__"inroom69",
                "east":__DIR__"inroom68",
               "south":__DIR__"inroom62",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
