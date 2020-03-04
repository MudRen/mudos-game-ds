#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門之上");
 set("long",@LONG
你現在身處巨石門之上, 山下動靜都可以清楚的看見,
整個巨石門只有這裡的正下方才有通道往裡面走, 因此這
邊的防守也特別嚴密, 有許多的侍衛都在這邊巡視.
LONG
    );
 set("exits",([ "east":__DIR__"outdoor5",
                "west":__DIR__"outdoor6",
                "down":__DIR__"outdoor1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}