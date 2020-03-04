#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟宿舍"NOR);

 set("long",@LONG
這裡是天梟第十七代弟子的休息場所, 只見室內的陳設相
當的簡單, 除了一大張通鋪以外就只有一些陳舊的木桌和木椅
以及一隻青銅塑成的大梟, 在這裡往北走就可以到達天梟弟子
的集會場所及練武場, 往東則可回到十八代弟子的寢室.
LONG
    );
 set("exits",([ "north":__DIR__"bird10",
                     "east":__DIR__"bird7",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 3,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
