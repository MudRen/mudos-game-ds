#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"蓮池"NOR);

 set("long",@LONG
這裡是天梟藥園中栽培近水植物的地區, 你如果是天梟的
門人, 大概都可以在這裡找到你所需要的藥材, 如果找不到, 
也可以去藥材室裡買到.
LONG
    );
 set("exits",([ "east":__DIR__"med4",
		"south":__DIR__"med2",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}