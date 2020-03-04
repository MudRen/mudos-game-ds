#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","藥園");

 set("long",@LONG
從這裡進去就是天梟的藥園了, 自天梟創派以來, 就一直是
在這裡種植藥材, 天梟分裂後, 冶藥一派隱入十萬大山中, 就接
下了這個藥園.
LONG
    );
 set("exits",([ "east":__DIR__"med2",
		"south":__DIR__"med21",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}