#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","南無砂港泊口");
set("long",@LONG
你到了這裡才知道是什麼事拖住了, 你看到一個船夫正對
商客們舉臂大吵!  也許就是因為這樣才拖住了商客們吧? 話不
多說, 是非之地不宜久留!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun41",
"enter":__DIR__"fishing",
	"south" : "/open/world1/ksj/lost_island/room_add",
]));
 set("objects", ([__DIR__"../npc/boatman" : 1,
    ]));
  set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            





