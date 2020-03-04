#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門之上");
 set("long",@LONG
你現在身處巨石門之上, 山下動靜都可以清楚的看見,
這個地方是巨石門的西側, 靠近山林, 杭山之西的森林可
以由此處監視. 你的再西側尚有一個小階梯可以通往西邊
下方的小路.
LONG
    );
 set("exits",([ "westdown":__DIR__"outdoor7",
                "down":__DIR__"outdoor3",
                "east":__DIR__"outdoor4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}