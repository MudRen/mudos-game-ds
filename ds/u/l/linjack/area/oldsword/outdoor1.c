#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門下");
 set("long",@LONG
你現在身在向雲堂前的一個巨大石門, 看起來向是一座小
城牆, 煞是壯觀. 石門上下都站了數名侍衛, 守備森嚴. 通過
了石門就算向雲堂內了. 左右都還有路. 有個樓梯可通往石門
頂.
LONG
    );
 set("exits",([ "north":__DIR__"outroom6",
                "south":__DIR__"mountroad1",
                "east":__DIR__"outdoor2",
                "west":__DIR__"outdoor3",
                "up":__DIR__"outdoor4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}