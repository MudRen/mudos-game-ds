#include <room.h>
inherit ROOM;
void create()
{
 set("short","二樓休息室走道盡頭");
 set("long",@LONG
這裡是休息室二樓, 這個樓層大多住的是比較中下階級
的侍衛或是較資淺的弟子. 地板上有一些土黃色的刮痕, 仔
細一看原來是有些砂土刮在地上. 南北兩側的廂房有正在練
功的聲音, 最好不要進去打擾他們. 東側有扇通往儲藏室的
門.
LONG
    );
 set("exits",([ "north":__DIR__"inroom53",
                 "west":__DIR__"inroom49",
                "south":__DIR__"inroom54",
                 "east":__DIR__"inroom55",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
