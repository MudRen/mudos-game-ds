#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","東副師部");
set("long",@LONG
這裡是位於主海政部東邊的東副師部, 你可以從你現在的
位置看到一個大概和海政司長官一樣忙得不可開交的東副師, 
他正在公文山中拼命....
LONG
    );
 set("exits",([ "west":__DIR__"seacoun11",
]));
 set("objects", ([__DIR__"npc/bladeguard" : 1,
		  __DIR__"npc/east_secretary" : 1,
    ]));

 set("no_clean_up",0);
  set("light",1);
 setup();
 replace_program(ROOM);
}             
