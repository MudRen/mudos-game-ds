#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟後院"NOR);

 set("long",@LONG
你可以在這裡看到三三兩兩的天梟第十八代,第十九代弟
子在這裡談天說地, 在他們的身旁有一些甜點, 這裡真可以說
是天梟的休息室了, 你心裡不禁為眼前的景象, 感到一股莫名的欣
慰, 這才是你心中的天梟啊!! 
LONG
    );
 set("exits",([ "northwest":__DIR__"eastroad6",
                "southwest":__DIR__"eastroad4",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 2,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
