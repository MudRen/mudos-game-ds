#include <room.h>
inherit ROOM;
void create()
{
 set("short","二樓休息室走道");
 set("long",@LONG
這裡是休息室二樓, 這個樓層大多住的是比較中下階級
的侍衛或是較資淺的弟子. 地板上似乎有一些被重物壓過的
痕跡. 南北兩邊的房間中有些唸口訣的聲音, 像是有人在練
功.
LONG
    );
 set("exits",([ "north":__DIR__"inroom50",
                 "east":__DIR__"inroom52",
                "south":__DIR__"inroom51",
                 "down":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
