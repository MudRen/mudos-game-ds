#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你繼續往深處走下去, 又遇到了一群比剛才還要
大的狐狸, 你心想既然你已經到這了, 絕對不能就在
這被打倒了, 因此你奮力的向狐狸撲了過去.
LONG
    );
 
 set("exits",(["northeast":__DIR__"en17",
               "southwest":__DIR__"en15",
           ]));
 set("objects",([__DIR__"npc/fox5" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
