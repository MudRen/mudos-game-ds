#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG
你強忍著令人噁心的臭味四處走了走, 向四周望去, 突然發
現了好幾具屍骸，應該是在此處迷路的路人, 不幸遭到巨蟲的攻
擊後, 所留下的. 在暗處發現了幾隻你從未看過的巨大蟲類, 正
在啃食地上的白骨, 毛骨悚然的感覺正湧上心頭.
LONG);
 set("exits",(["west":__DIR__"en53",
               "southwest":__DIR__"en57",
               "southeast":__DIR__"en59",
               ]));
 set("objects",([__DIR__"npc/bug" : 2+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

