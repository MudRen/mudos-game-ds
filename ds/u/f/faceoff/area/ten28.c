#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","壩子");

 set("long",@LONG
從這裡你可以相當清楚的看到壩子中的農耕區, 其實十萬大
山的土壤並不適合來耕種, 但是在此耕作的都是一些沒有金錢去
山下購買土地的貧農, 只好在此拓荒....
LONG
    );
 set("exits",([	"south":__DIR__"ten27",
		"north":__DIR__"ten29",
    ]));
 set("objects", ([__DIR__"npc/farmer1" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}