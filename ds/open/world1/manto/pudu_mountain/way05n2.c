#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "山崖小徑");
  set("long", @LONG
攀到了此處，山壁中間凹進一行棧道。沿著棧道走上山，走
了莫約十里路，只見道路越接近山頂，越是狹窄，路面也越是坎
坷不平。在你前面是處深埋在山林深處的莊園，靜悄悄地，竟是
沒有一絲氣息。
LONG
);
  set("exits", ([ 
  "south" : __DIR__"way05n",  
    "north" : "/open/world1/tmr/unquiet_manor/map_17_8",
]));
        set("outdoors","land");

        setup();
}

