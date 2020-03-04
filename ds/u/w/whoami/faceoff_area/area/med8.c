#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"溫室"NOR);

 set("long",@LONG
這裡是溫室的延伸, 你發現你的東方似乎有一個大大的不
明物體, 你的好奇心驅使你往那邊去看一看....
LONG
    );
 set("exits",([ "east":__DIR__"med9",
		"south":__DIR__"med7",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}