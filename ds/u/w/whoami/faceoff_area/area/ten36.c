#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");

 set("long",@LONG
你的雙腳正踩在通往天梟冶藥一派的青石路上, 你發現一
路上並沒有什麼行人, 看來天梟冶藥一派並不喜歡太多的人, 
不曉得他們歡不歡迎你....
LONG
    );
 set("exits",([	"north":__DIR__"ten37",
		"south":__DIR__"ten35",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}