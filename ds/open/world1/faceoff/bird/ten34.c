#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","蛇穴");

 set("long",@LONG
這裡是蛇穴的深處, 你看到一隻巨蛇盤踞在此, 從牠的眼睛
你可以看出牠想把你殺了, 附近都是一堆堆的屍骨, 讓你不寒而
慄.
LONG
    );
 set("exits",([	"west":__DIR__"ten33",
    ]));
 set("objects", ([__DIR__"npc/large_viper" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}