#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的森林泥沼區, 這兒景色的恐怖, 
使你心裡毛毛的, 不時還聽到些叫聲, 應該是那不知名
的動物所發出的吧.

LONG
    );
 
 set("exits",(["east":__DIR__"en56",
               "northeast":__DIR__"en52",
               "south":__DIR__"en60",
               ]));
 set("objects",([__DIR__"npc/animal" : 4,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
