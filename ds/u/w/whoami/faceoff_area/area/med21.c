#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"晦林"NOR);

 set("long",@LONG
你終於舒了一口氣, 從這裡往東走就可以離開這個潮溼的
地方了, 你忽然想起在晦林中都沒有看到會飛的昆蟲, 想來是
因為水氣會沾上翅膀, 所以沒有飛蟲吧?
LONG
    );
 set("exits",([ "west":__DIR__"med22",
		"east":__DIR__"med18",
		"south":__DIR__"med20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}