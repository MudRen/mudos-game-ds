#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","海政司-中庭");
set("long",@LONG
你現在正置身於海政司的中庭, 由於無砂鎮和西方貿易極
盛, 因此原本單純的戶政事務以變的繁複無比, 你的東邊是負
責處理東方戶政的東戶部, 而西邊當然就是西戶部囉! 如果往
北則會到負責處理一切貿易的海政長官處了.
LONG
    );
 set("exits",([ "east":__DIR__"seacoun14",
		"west":__DIR__"seacoun16",
		"north":__DIR__"seacoun10",
		"out":__DIR__"seacoun8",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
