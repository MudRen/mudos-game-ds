#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城東道");
        set("long", @LONG
這裡是地下城的東走道的部分，在這條街上有許多從地上聖˙都來
觀光的地上人，南邊的旅店有許多的地上主城觀光團的人住宿，也有許
多高級官員在那留宿過。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec5.c",
     "east":__DIR__"sec7.c",
     "south":__DIR__"waiter.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
