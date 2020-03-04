#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","黃土小路");
 set("long",@LONG
這是一條通往東方的黃土小路﹐森林中靜悄悄地聽不見蟲鳴
鳥叫﹐使人不禁緊張起來﹐一株株高大的樹木彷彿上面都躲著攔
路行搶的強盜﹐如果你沒有其他的事﹐最好還是趕快離開以免遭
遇不測.
LONG
    );
 set("exits",([ "westdown":__DIR__"ten3",
                "northeast":__DIR__"ten5",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

