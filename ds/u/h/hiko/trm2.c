#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"【"HIY"測試間"HIW"】"NOR);
        set("long",
         "這裡是專門來測試的地方，有著許\多心血的結晶都是在此誕生\n"
         "在這，讓你行走起來較為困難，而且還能看到許\多改過的草稿，看\n"
         "來要做出新作品也是很累的的，因此讓人格外感到感觸，而這也是\n"
         "飛羽光正在努力的，不過還是非常的趕工\n" 
         );
        
set("exits", ([
    "east" : __DIR__"trm1",             ])); 
set("objects",([__DIR__"npc/testmob" : 1]));        
setup();
}


