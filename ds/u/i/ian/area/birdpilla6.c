#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
你跌跌撞撞的來到轉角處, 不禁打從心底歡呼一聲, 只見一條長長的
石廊, 上面的牆壁上雕刻了許多鳥類飛翔的浮雕, 栩栩如生, 牆上浮雕的
鳥兒彷彿要自牆上飛出一般, 石廊牆上懸著油燈, 燈中燭火搖擺不定, 使
的冷清清的石廊更顯的神秘, 你可以隱隱約約的看到石廊的盡頭, 是一扇
石門...   
LONG
    );
 set("exits",([ "south":__DIR__"birdpilla5",
                "east":__DIR__"birdpilla7",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

