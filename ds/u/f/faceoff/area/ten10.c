#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","奇倪峰");

 set("long",@LONG
你費盡了千辛萬苦, 終於踏上了奇倪峰的土地, 真是讓你感
動萬分, 從這裡往東則是回到滅骨峰的山路, 再往西北方前進則
會到望月崖.
LONG
    );
 set("exits",([	"west":__DIR__"ten11",
		"eastdown":__DIR__"ten9",
		"north":__DIR__"ten13",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}