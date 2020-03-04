#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"走道"NOR);

 set("long",@LONG
進入到這才能算進到天梟冶藥一派, 你發現這裡和天梟武
學一派一樣, 牆上有許多精美的雕刻, 你同時也發現你的東南北
都是一條長長的走道, 往西則是你走進天梟的路.
LONG
    );
 set("exits",([ "east":__DIR__"pill3",
	    "west":__DIR__"pill1",
            "north":__DIR__"walk1",
            "south":__DIR__"walk2",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           
           
