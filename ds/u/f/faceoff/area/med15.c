#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"針林"NOR);

 set("long",@LONG
這裡已經是針林的末端了, 你可以感覺到四周的溫度的確
較高了一些, 但是還是有許多的寒帶植物生長在這, 你可以在
這採到一些你要的藥材.
LONG
    );
 set("exits",([ "east":__DIR__"med14",
		"north":__DIR__"med16",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}