#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"岔道"NOR);

 set("long",@LONG
這裡是一個三岔路口, 往東有一條小小的老舊石板路, 往
西則是一條由官府修緝的棧道, 而往南則通往你所來的道路,
你舉目一望, 十萬大山著名的峭壁就挺拔的豎立在你的面前, 
你心中實在拿不定主意要走哪一條....
LONG
    );
 set("exits",([ "south"__DIR__"ten_mountain3",
                "east":__DIR__"ten_mountain5", 
                "west":__DIR__"ten_mountain8",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
