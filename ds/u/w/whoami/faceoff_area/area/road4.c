#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
這裡的景色已經沒啥好描述的了, 四處是一片一望無際的
原野, 你心中忽然想道: 不知道如果這邊的原野皆開墾為農田
會是如何的情景?...
LONG
    );
 set("exits",([ "southwest":__DIR__"road3",
		"northeast":__DIR__"road5",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
