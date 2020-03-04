#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"晦林"NOR);

 set("long",@LONG
你發現你似乎身處在一個大大的蒸氣室中, 渾身又溼又癢, 
原來這裡就是天梟藥園中的晦林, 你心想, 趕快採完藥材趕快
出去吧....
LONG
    );
 set("exits",([ "east":__DIR__"med17",
		"west":__DIR__"med21",
		"south":__DIR__"med19",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}