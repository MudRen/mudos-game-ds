#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");

 set("long",@LONG
從這裡往西走會到在藥園最溼且暗的晦林, 那裡培埴的皆
是一些喜好陰濕的植物, 不過, 走進去是一件相當難受的事就
是了...
LONG
    );
 set("exits",([ "west":__DIR__"med18",
		"east":__DIR__"med16",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}