#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集大門");
set("long",@LONG
這裡是市集的大門, 你可以看見兩隻無砂的代表物, 白石獅, 
正倒臥在紅漆大門邊, 而紅漆大門上的匾額寫著: 四海皆兄弟, 
不過顯然這裡的交易早已不只用四海皆兄弟來形容囉!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun22",
		"south":__DIR__"seacoun26",
]));
 set("objects", ([__DIR__"npc/sea_guard" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            