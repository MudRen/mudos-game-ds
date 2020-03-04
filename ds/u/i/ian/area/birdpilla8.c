#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石廊盡頭"NOR);

 set("long",@LONG
你按捺著心裡的激動, 走到了石廊的盡頭, 油燈越靠近石廊盡頭, 越
是光亮, 你這時心中已無任何害怕的感覺, 你只想揭開這個古老教派的神
秘面紗, 你小心的走到石廊盡頭, 探頭往內一看, 只見並沒有你想像的荒
廢蕭然, 也沒有三步一崗, 五步一哨的嚴密防守, 你看到一個空蕩蕩的石
室, 中央放著一個石臺, 有幾個人在石臺前不知道在做什麼...
LONG
    );
 set("exits",([ "north":__DIR__"guild", 
                "west":__DIR__"birdpilla7",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

