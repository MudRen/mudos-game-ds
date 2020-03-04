#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你來到了東北澤林的伐木區, 這裡有許多的橋夫, 正在努力
的砍伐樹木, 他們的汗一滴一滴的流下, 再往北走就是無人的森
林深處了。 
LONG);
 
 set("exits",(["north":__DIR__"en6",
               "west":__DIR__"en3",
             ]));
 set("objects",([__DIR__"npc/cutter" : 3+random(5),
               ]));
 
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}

