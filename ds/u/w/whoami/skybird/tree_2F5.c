#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","神鷹穴");

 set("long",@LONG 
這裡就是散發出濃烈神聖氣息的神鷹穴, 這裡的神聖氣息使
你輕易就感到裡面住了一隻頗富靈性的神鷹, 你仔細看了看穴壁
, 發現都是非常罕見的極為珍貴的草葉或草梗所製成的. 可見裡
面的神鷹也頗通醫藥之學.....
LONG
    );
 set("exits",([ "west":__DIR__"tree_2F1",
                "east":__DIR__"tree_2F1",
                "north":__DIR__"tree_2F5",
                "south":__DIR__"tree_2F1",
    ]));
set("objects",([__DIR__"npc/holy_eagle":1,

]));
 set("no_clean_up", 0);
 set("no_map",1);
 setup();
 replace_program(ROOM);
}

