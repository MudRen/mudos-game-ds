#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪");
 set("long",@LONG
這邊是向雲堂西北方向的小草坪, 被夾在山谷之中, 只有
這一塊小小的空地, 偶爾有一些小動物在這邊出沒. 地上有些
顏色鮮艷的花, 拿來當裝飾應該不錯. 東北方向有條岔路.
LONG
    );
 set("exits",([ "southup":__DIR__"inroom21",
                "north":__DIR__"outroom17",
                "northeast":__DIR__"outroom18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
