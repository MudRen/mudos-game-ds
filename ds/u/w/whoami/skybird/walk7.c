#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"北走道"NOR);
 set("long",@LONG
這裡已經是北走道的末端了, 再往前走就是天梟冶藥一派
專門提供客人或十萬大山遊客休息的客房, 裡面有許多求醫者
, 膜拜者和遊客, 但卻相當乾淨, 往南走則會回到北走道.
LONG
    );
 set("exits",([ "north":__DIR__"bed1",
            "south":__DIR__"walk5",
            "east":__DIR__"bed2",
]));
set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
