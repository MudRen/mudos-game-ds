#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","蛇穴");

 set("long",@LONG
原來這裡是蛇的居住地! 二話不說, 趕快往外走吧, 但是如果
你膽子夠大, 也可以再往內走.
LONG
    );
 set("exits",([	"out":__DIR__"ten23",
		"east":__DIR__"ten34",
    ]));
 set("objects", ([__DIR__"npc/viper" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}