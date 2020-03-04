#include <room.h>
inherit ROOM;
void create()
{
 set("short","左偏廳");
 set("long",@LONG
你通過了一個走道來到了左偏廳, 左偏廳這邊望去, 是一片廣
大的平原, 平原再過去就是塞外邊疆了, 這邊的景色平常沒有右偏
廳的好, 不過在日暮西下的時候, 卻也有意想不到的景色. 你要再
出去一點看風景的話, 外面還有一條走道, 上面有一個高塔不知道
是作什麼的, 你可以爬旁邊的樓梯上去看一看.
LONG
    );
 set("exits",([ "east":__DIR__"inroom67",
                "west":__DIR__"inroom12",
                  "up":__DIR__"inroom11",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
