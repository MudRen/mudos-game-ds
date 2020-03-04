#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門下");
 set("long",@LONG
你現在身在向雲堂前的一個巨大石門, 看起來向是一座小
城牆, 煞是壯觀. 石門上下都站了數名侍衛, 守備森嚴. 這邊
是石門的西側, 有一條樓梯可以往上走到石門之上, 往西的方
向還有通路, 不過要從石門上才能通達.
LONG
    );
 set("exits",([ "east":__DIR__"outdoor1",
                "up":__DIR__"outdoor6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}