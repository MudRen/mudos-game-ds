#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
這裡仍然是一片寬廣的原野, 而這條小路也越行越小, 不過
十萬大山就在你東北方不遠處, 這裡的地表已經有一些起伏, 相
當不好行走....
LONG
    );
 set("exits",([ "northeast":__DIR__"road6",
		"southwest":__DIR__"road4",
]));
 set("objects", ([__DIR__"npc/mountain_cat": 4,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
