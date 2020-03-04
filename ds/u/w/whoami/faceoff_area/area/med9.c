#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"溫室"NOR);

 set("long",@LONG
你發現原來那個大大的不知名物體是一個大大的甕, 裡面
裝了相當多的滾水, 四周塞以樹葉等物, 用來提供東北地區所
沒有的高溫.
LONG
    );
 set("exits",([ "south":__DIR__"med10",
		"west":__DIR__"med8",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}