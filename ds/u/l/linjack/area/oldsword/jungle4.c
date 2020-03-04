#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
你所在的叢林從此開始分了兩條明顯的通路出來, 看起來
幾乎一模一樣, 一條在北邊, 一條在東邊. 你在這邊已經可以
隱約聽到一些野獸嗷嘯的聲音.
LONG
    );
 set("exits",([ "east":__DIR__"jungle5",
		"west":__DIR__"jungle3",
                "north":__DIR__"jungle11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}