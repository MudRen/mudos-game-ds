#include <room.h>
inherit ROOM;
void create()
{
 set("short","天橋中央");
 set("long",@LONG
這邊是天橋的中央, 左右各還有一個平台可以站過去. 這裡
的地上有個奇怪的圓形圖騰, 不知道有什麼含義. 而且這邊竟然
有派較高階的護衛把守此處, 看來這圖騰有些玄機....
LONG
    );
 set("exits",(["south":__DIR__"inroom36",
               "east":__DIR__"inroom38",
               "west":__DIR__"inroom39",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
