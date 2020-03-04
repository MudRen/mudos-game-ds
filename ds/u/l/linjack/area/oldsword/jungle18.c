#include <room.h>
inherit ROOM;
void create()
{
 set("short","洞穴前");
 set("long",@LONG
有驚無險的通過了那些猛獸, 又走了一段時間, 你來到一處隱
蔽的山洞之前, 山洞之中蘊藏一股強大的氣息, 令你在外面就已經
有點喘不過氣來, 而且洞中似有燈火....? 可是洞穴的入口被一塊
巨石給擋住了.
LONG
    );
 set("exits",([ "southeast":__DIR__"jungle19",
                "north":__DIR__"jungle17",
                "west":__DIR__"jungle16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}