#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石廊"NOR);

 set("long",@LONG
這裡的教眾便的安靜多了, 不再像先前那般鬧哄哄的亂成一團, 石廊內
也涼快了許多, 天梟教眾們開始安靜的默禱, 這裡, 給你一種靜謐的感覺,
讓你疲累的身心得到舒解, 你感覺輕鬆了許多, 心情也沒有剛進來時那般七
上八下了. 
LONG
    );
 set("exits",([ "east":__DIR__"guilda",
                "north":__DIR__"guildc",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

