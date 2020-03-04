#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中小徑");
 set("long",@LONG
你發現這邊有一條小溪, 淙淙的流著, 可是你找不到這條
小溪的源頭, 似乎是從山壁中滲透出來的..但你沒有那種心思
去注意它了, 你開始覺得你已經深入一個危險的地方.
LONG
    );
 set("exits",([ "west":__DIR__"bandit3",
                "east":__DIR__"bandit5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
