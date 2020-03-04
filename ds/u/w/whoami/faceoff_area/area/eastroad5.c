#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小徑"NOR);

 set("long",@LONG 
這裡是天梟客房往東南的出口所通向的小徑, 只見藍天白雲
, 在旁常綠樹木百年長青, 你心中忽然汎起平凡即是至美這句話
來, 真是好一幅寧靜祥和的天上美景啊!! 
LONG);
 set("exits",([ "northwest":__DIR__"eastroad6",
                "southwest":__DIR__"eastroad4",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 2+random(3),
    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

