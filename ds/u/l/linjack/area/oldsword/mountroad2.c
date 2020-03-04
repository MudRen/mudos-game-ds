#include <room.h>
inherit ROOM;
void create()
{
 set("short","山路的盡頭");
 set("long",@LONG
這一段路你幾乎都是低著頭在走, 忽然你發現你腳踏之地
已經不是一片黃土路了! 你一抬頭, 往前望去, 就已經可以從
樹縫之中看到壯觀的向雲堂了!
LONG
    );
 set("exits",([ "northwest":__DIR__"mountroad1",
                "southdown":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
