#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"書院"NOR);
 set("long",@LONG
這裡就是天梟冶藥一派的書院, 這裡的學生不多, 但是在講
台上的講師卻十分賣力的授課. 據說天梟治藥一派引以為傲的藏
書閣就在這書院的後方.
LONG);
 set("exits",(["southeast":__DIR__"pill3",
    ]));
/* set("item_desc",([
        "柱子":"一根大大的柱子, 從這個角度看不出有什麼異常.\n"
    ]));
*/
 set("objects", ([__DIR__"npc/teacher" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

