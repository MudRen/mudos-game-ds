//updated 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"Circle tunnel＠Saint"NOR);
       set("long",@long
你正走著一條連接saint 城和礦區的行人通道，往南直走可通往舊世
界採礦區，往北不遠處就是城門了，盡是擁擠的人潮。這條通道呈處在一
圓管形的防護薄膠中，完全地隔離了礦區中汙穢難聞的空氣。
long
);
	set("exits", ([ /* sizeof() == 1 */
  // "south" : __DIR__"pass1.c", 改連礦場
"enter":__DIR__"gate1.c",
]));
   set("outdoors","land");
	setup();
}
