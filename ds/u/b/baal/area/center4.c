#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"青石廊"NOR);
 set("long",@LONG
青色的大石平鋪在地板上, 這裡是教眾與鳥兒的世界, 石廊頂, 鳥兒
在上忙碌的穿梭來去, 石廊底, 教徒如潮水一般的湧進.
LONG
    );
 set("exits",([ "east":__DIR__"center3",
                "north":__DIR__"guildg",
                "south":__DIR__"guildf", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
