#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大通鋪"NOR);
set("long",@LONG
這裡是天梟提供來訪者休憩的正東邊床位, 你發現這裡休
憩大部份是虔誠的天梟教徒, 也許你可以問一問他們天梟的教
義及信仰..
LONG
    );
 set("exits",([ "north":__DIR__"bed2",
            "south":__DIR__"bed4",
]));
 set("objects", ([__DIR__"npc/prayer" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
