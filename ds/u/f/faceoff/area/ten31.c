#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
這裡是壩子中的農耕區, 你發現有一些辛勞的莊稼漢正在辛
勤的工作, 但是這裡的土壤真的不適合耕作, 就算再努力工作, 
收成也相當有限.
LONG
    );
 set("exits",([	"south":__DIR__"ten32",
		"north":__DIR__"ten30",
    ]));
 set("objects", ([__DIR__"npc/farmer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}