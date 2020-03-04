#include <room.h>
inherit ROOM;
void create()
{
 set("short","湖中走道");
 set("long",@LONG
這條走道左右兩旁各有一個小池塘, 蠻深的. 有些魚在裡
面游著, 說不定可以在這邊釣魚, 但是走道上還是有些守衛,
如果你要釣的話最好不要給他們發現.....
東邊有條小吊橋可以穿過這個水塘.
LONG
    );
 set("exits",([ "north":__DIR__"outroom1",
                "south":__DIR__"outroom6",
                 "east":__DIR__"outroom7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
