#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你繼續往西南走, 你看到地下有些很大的腳印, 這應該是傳
說中的動物「千年巨蛙」所留下的, 據說這些巨蛙很兇猛, 看到
牠最好快走.
LONG);
 set("exits",(["west":__DIR__"en49",
               "northeast":__DIR__"en47",
               ]));
 set("objects",([__DIR__"npc/tfrog" : 4+random(3),
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

