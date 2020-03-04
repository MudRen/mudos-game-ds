#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"秋錦家"NOR);
 set("long",@LONG
你到了一棟小木屋, 這裡陳列著各式各樣的布匹, 這些布摸
起來的觸感非常好, 應是一位織布的高手所做的作品, 你看到的
全是少女的日用品, 所以這應是少女的房間.
LONG
    );
 
 set("exits",(["east":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/chiu" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        

