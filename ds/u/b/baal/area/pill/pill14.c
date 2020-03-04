#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"東走道"NOR);

 set("long",@LONG
這裡是天梟針灸一派的後半部, 從這裡往東北方走會通向
天梟針灸一派的藏書閣, 那裡有許多關於針灸知識的書籍, 往
東南則是膜拜室.
LONG
    );
 set("exits",([ "northeast":__DIR__"pill15",
                "southeast":__DIR__"pill16",
                "west":__DIR__"pill13",
    ]));
// set("objects", ([__DIR__"npc/birdguard" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);          
}
