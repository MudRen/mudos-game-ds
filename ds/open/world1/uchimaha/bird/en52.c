#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的森林泥沼區, 你一來這就有一股惡
心的味道湧上鼻頭, 地上有幾隻巨大的蟲正在爭著啃食死
屍, 你不禁感到毛骨悚然, 想要快點離開這裡.

LONG
    );
 
 set("exits",(["east":__DIR__"en53",
               "southwest":__DIR__"en55",
               "southeast":__DIR__"en57",
               ]));
 set("objects",([__DIR__"npc/bug" : 3,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
