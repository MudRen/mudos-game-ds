#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門之上");
 set("long",@LONG
你現在身處巨石門之上, 山下動靜都可以清楚的看見,
這個地方是巨石門的東側, 靠近山林, 杭山之東的森林可
以由此處監視.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor4",
                "down":__DIR__"outdoor2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}