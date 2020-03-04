#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"木樁陣中"NOR);

 set("long",@LONG
你覺得四周被木樁擠的換不過氣來, 既之發現這是你的心理作用, 
可見對你已經感到一定程度的心慌意亂了....你心中不禁希望感
快走出這一個令人心慌了地方....
LONG
    );
 set("exits",([ "west":"/u/f/faceoff/wood3.c",
                "east":"/u/f/faceoff/wood1.c",
                "north":"/u/f/faceoff/wood2.c",
                "south":"/u/f/faceoff/wood5.c",
    ]));

 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}