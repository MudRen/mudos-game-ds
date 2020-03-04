#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
[B[B在山洞中, 連洞口的光線都透不進來了, 你只能靠山洞斜頂上的破
洞傳來的微弱光線隱隱約約辯認出山洞內的景物, 奇怪的是, 山洞斜頂
上的破洞似乎不是天然形成的, 他們之間似乎有一定距離...
LONG
    );
 set("exits",([ "south":__DIR__"birdpill2",
                "west":__DIR__"birdpill4",
                "east":__DIR__"birdpill5",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

