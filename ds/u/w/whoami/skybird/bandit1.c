#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","寨門");
 set("long",@LONG 
你壯著膽子進了寨門, 只見四周的守衛相當嚴密, 壁上還有
一些箭孔可以向外射箭, 不要說官兵根本不管這裡, 就算要管, 
要進攻進去也很難.
LONG
    );
 set("exits",([ "northwest":__DIR__"bandit3",
                "southeast":__DIR__"bandit2",
                "northeast":__DIR__"bandit4",
                "out":__DIR__"ten6",
    ])); 
 set("objects", ([__DIR__"npc/archer" : 1+random(4),
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();
 create_door("out","厚重鐵門","enter",DOOR_LOCKED,"nokey");
}

