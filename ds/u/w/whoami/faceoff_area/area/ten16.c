#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","寨牆");

 set("long",@LONG
這些是寨中的山賊們, 為了抵抗偶爾從山下來鏟除山賊的官
兵隊而築的牆, 牆非常的堅固, 而且牆上有許多的箭孔讓裡面可
以向外射箭, 看來很難攻進去….
LONG
    );
 set("exits",([	"south":__DIR__"ten6",
		"north":__DIR__"ten17",
    ]));
 set("objects", ([__DIR__"npc/yleader" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
