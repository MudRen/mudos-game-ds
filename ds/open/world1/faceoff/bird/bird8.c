#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟廚房"NOR);

 set("long",@LONG
你一跨進這個房間, 立刻被它所散發出的獨特香味所吸引, 
正在你對於這個香味讚嘆不已之際, 不知為何你想起了天梟
弟子的床, 你一轉念, 慢著! 天梟連床鋪都要講究溯本的精神
, 那他們該不會吃毛毛蟲吧 ?! 你想至此處,  剛才被引起的食
慾忽然消失無蹤....
LONG
    );
 set("exits",([ "south":__DIR__"bird7",
    ]));
set("objects", ([__DIR__"npc/cooker" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
