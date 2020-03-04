#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大通鋪"NOR);
set("long",@LONG
這裡是天梟提供來訪者休憩的東邊床位, 你發現這裡休憩
大部份是商人, 也許你可以和他們交易.
LONG
    );
 set("exits",([ "west":__DIR__"bed1",
            "south":__DIR__"bed3",
]));
 set("objects", ([__DIR__"npc/vendor" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
