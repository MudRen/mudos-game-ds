#include <room.h>
inherit ROOM;
void create()
{
 set("short","天橋");
 set("long",@LONG
你通過了奕之樓, 來到了天橋上. 你往斜後方一看, 就看得到
望旭觀暮兩座榙, 約和你同一個高度, 從此地俯看, 可以將整個向
雲山莊納入你眼廉之中, 你赫然發現, 整個向雲堂是崁入杭山之中
的, 杭山上有一直聳的山峰, 上面看起來金光四射.

LONG
    );
 set("exits",(["south":__DIR__"inroom35",
               "north":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
