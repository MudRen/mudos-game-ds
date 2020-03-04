#include <room.h>
inherit ROOM;
void create()
{
 set("short","元象卦");
 set("long",@LONG
你來到了一個約莫二十尺的大方形石板上, 上面壓著一個
大型的圓桶狀石桌, 高約三尺, 重達千斤. 你完全不知道這裡
有什麼做用, 是機關嗎? 還是....
LONG
    );
 set("exits",([ "east":__DIR__"outroom30",
                "north":__DIR__"outroom29",
                "southwest":__DIR__"outroom32",
                "southeast":__DIR__"outroom33",
                "south":__DIR__"secret1_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
