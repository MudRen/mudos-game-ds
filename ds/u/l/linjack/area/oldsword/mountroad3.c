#include <room.h>
inherit ROOM;
void create()
{
 set("short","往向雲堂的山路");
 set("long",@LONG
你在山中稀稀疏疏的樹林中穿梭了好一陣子之後, 總算到了
一處比較空曠的地方, 這邊的路已經寬廣多了, 但是兩旁仍是有
不少的樹木擋住遠方的視野, 不過你知道剩下來的這段山路已經
不會很長了.
LONG
    );
 set("exits",([ "northup":__DIR__"mountroad2",
                "west":__DIR__"mountroad2_1",
                "southeast":__DIR__"mountroad1_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}