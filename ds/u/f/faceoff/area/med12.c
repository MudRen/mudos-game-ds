#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");

 set("long",@LONG
你已經可以從這邊看到在東方不遠處的針林了, 只見東方
霧氣翻吞, 看來就是很冷的樣子, 難怪裡面種植的都是嗜寒植
物....
LONG
    );
 set("exits",([ "north":__DIR__"med11",
		"west":__DIR__"med13",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}