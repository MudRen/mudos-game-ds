#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道");

 set("long",@LONG
從這裡已經進入了羊腸道, 傳說這裡強盜相當的多, 但是進
入此處除盜的俠客也相當的多, 像邱奕捷就是其中的一個佼佼者
, 看來你應該要小心一些.
LONG
    );
 set("exits",([	"north":__DIR__"ten23",
		"southwest":__DIR__"ten21",
    ]));
 set("objects", ([__DIR__"npc/chiu" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}