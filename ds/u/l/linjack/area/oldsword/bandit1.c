#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中小徑");
 set("long",@LONG
你一走進這邊, 就覺得煙霧瀰漫, 使你的視線受到影響,
沒有辦法看清楚你到底在哪裡, 或許你可以往回走到森林之
中. 這邊有一股肅殺的氣息讓你覺得毛骨悚然......
LONG
    );
 set("exits",([ "south":__DIR__"forest7",
                "east":__DIR__"bandit2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
