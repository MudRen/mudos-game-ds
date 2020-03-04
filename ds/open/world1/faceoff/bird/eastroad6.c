#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟客房"NOR);

 set("long",@LONG
這裡的人群比之更西一點少了許多, 你往東看看, 又往西看
看, 原來這裡就是天梟一派招待重要來客時所用的大型客房, 
你聞到了一股股的裊煙味, 心中感到天梟對於遠方來客果然
是有如傳說中的禮數週到!! 
LONG
    );
 set("exits",([ "southeast":__DIR__"eastroad5",
                "southwest":__DIR__"eastroad7",
    ]));
set("objects", ([__DIR__"npc/bird_waiter" : 2,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
