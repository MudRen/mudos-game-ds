#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");

 set("long",@LONG
這裡仍然是青石路的一段, 依據你的經驗, 青色似乎是天梟
的代表色, 不過你行至此, 發現原來要去天梟冶藥一派的人也並
不在少, 不知道他們去做什麼?
LONG
    );
 set("exits",([	"north":__DIR__"ten38",
		"south":__DIR__"ten36",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}