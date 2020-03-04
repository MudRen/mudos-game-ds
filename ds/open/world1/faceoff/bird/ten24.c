#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道");

 set("long",@LONG
這裡已經接近了羊腸道的末端, 你不禁鬆了口氣, 終於可以
從這條小小小路出去了, 就在你慶幸之際, 忽然看見一個升著營
火的帳蓬在你附近, 也許是強盜的居所....
LONG
    );
 set("exits",([	"northeast":__DIR__"ten25",
		"southdown":__DIR__"ten23",
    ]));
 set("objects", ([__DIR__"npc/wind_ranger":2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}