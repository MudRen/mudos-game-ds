#include <room.h>
inherit ROOM;
void create()
{
 set("short","山道下");
 set("long",@LONG
你正在一個山道之下, 山道因為年久失修, 已經長滿青苔,
而且石階經風吹雨打之後已經殘破不全, 也沒有輔助爬坡的欄
杆或是木樁, 看來輕功不夠好的人是上不去的. 或許你可以借
助一些裝備來通過山道.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor9",
                "east":__DIR__"outdoor10",
                "northup":__DIR__"outdoor12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}