#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
這裡仍然是壩子中的農耕區, 你發現四周有些農民軍正在四
處巡邏, 看有無可疑份子在四周活動, 畢竟這附近的強盜勢力非
常強大.
LONG
    );
 set("exits",([	"east":__DIR__"ten27",
		"north":__DIR__"ten31",
    ]));
 set("objects", ([__DIR__"npc/soldier" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}