#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
這裡的地面還是濕濕滑滑的，但比較沒之前那麼嚴重了，但
是這裡的地面似乎常常在震動，而且幾乎沒停止過。不知會不會
到一半突然整個洞垮下來••
LONG
    );

       set("exits",([      
       "west":__DIR__"s14", 
           ]));
	set("objects", ([
      __DIR__"npc/anthropophagi-monster" : 3,
      __DIR__"npc/horn-monster" : 3,
    __DIR__"npc/predator-monster" : 3,
    __DIR__"npc/rough-monster" : 3,
    __DIR__"npc/single-monster" : 3,

 ]));
 set("no_clean_up", 0);
 setup();
}

