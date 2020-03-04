#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟西生堂"NOR);

 set("long",@LONG
這裡可以說是天梟的藥堂, 萬一有天梟的兄弟不幸受傷, 就
可以來這裡治療, 據說手藝並不比天梟攻丹一派差, 你聞了聞這
裡的藥味, 竟然令人感到心曠神怡! 從這裡往東就可以回到天梟
大院了, 這裡給人一種完全不同於東邪堂的感覺,到處生氣蓬勃,
如果你有傷口, 可以看看這裡的人願不願意為你醫療.
LONG);
 set("exits",([ "east":__DIR__"bird2",
    ]));
set("light",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}

