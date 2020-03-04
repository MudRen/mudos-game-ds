#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"針林"NOR);

 set("long",@LONG
你發現針林到處都是霧氣, 使你很難看到前面有啥東西, 但
是要採藥還是沒有困難的, 你不禁感嘆這樣的地理現象的神奇,
令人嘆為觀止.
LONG
    );
 set("exits",([ "west":__DIR__"med15",
		"north":__DIR__"med13",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}