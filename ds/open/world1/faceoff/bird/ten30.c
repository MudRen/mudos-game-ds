#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
這裡有一些農人正在喝水休息, 你發現這裡的農民都有一邊
工作一邊唱歌的習慣, 你發現他們都是以歌唱來抒發自己的情緒
以及生活狀況....
LONG
    );
 set("exits",([	"south":__DIR__"ten31",
		"east":__DIR__"ten29",
    ]));
 set("objects", ([__DIR__"npc/farmer1" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}