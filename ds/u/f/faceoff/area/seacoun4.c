#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","無砂鎮");
set("long",@LONG
你的面前就是無砂鎮了, 只見人潮洶湧, 到處都是叫賣聲, 
可見這裡是一個相當繁榮的商港, 不過三年前可不是這樣, 三年
前這裡處處是鹽田, 直到鎮長林繁榮上任才將其經營成商業魚港
, 才有今天的無砂鎮, 從這裡往北會到海政司, 往南則會到魚市
場.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun5",
		"west":__DIR__"seacoun3",
		"south":__DIR__"seacoun20",
		"east":__DIR__"seacoun29",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
