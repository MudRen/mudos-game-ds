#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這邊是一個分叉路的中心點, 往東北走可以看到一絲光線,
往南走不知道是什麼, 而往西走可以繼續在這個通到上活動..
LONG
    );
 set("exits",([ "northeast":__DIR__"secret3_8",
                "west":__DIR__"secret3_5",
                "south":__DIR__"secret3_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
