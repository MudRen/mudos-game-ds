#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道");

 set("long",@LONG
終於可以看到羊腸道的末端了, 羊腸道的末端就在你的東北
方不遠處, 你發現這裡奇蹟似的有一些義民軍在把守, 維護在壩
子中生活的農民.....
LONG
    );
 set("exits",([	"northeast":__DIR__"ten26",
		"southwest":__DIR__"ten24",
    ]));
 set("objects", ([__DIR__"npc/wind_ranger" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}