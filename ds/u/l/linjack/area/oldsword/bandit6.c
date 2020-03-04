#include <room.h>
inherit ROOM;
void create()
{
 set("short","林間的小空地");
 set("long",@LONG
你來到了一塊比較空曠的空地中, 可是仍然被樹林所籠罩,
看起來你還沒有離開這個恐怖的地方, 你心中漸漸開始惶恐了
起來.......
LONG
    );
 set("exits",([ "northeast":__DIR__"bandit7",
                "south":__DIR__"bandit5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
