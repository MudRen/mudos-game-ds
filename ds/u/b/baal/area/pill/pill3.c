#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"走道"NOR);

 set("long",@LONG
這裡再往東走就是天梟針灸一派的大廳了, 往西則通向北
走道和南走道, 你發現要往東去大廳的人極多, 然而大部份都
不是天梟弟子, 而是一些遊人
LONG
    );
 set("exits",([ "east":__DIR__"pill4",
                "west":__DIR__"pill2",
    ]));
// set("objects", ([__DIR__"npc/traveller" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
