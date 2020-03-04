#include <room.h>
inherit ROOM;
void create()
{
 set("short","觀暮塔");
 set("long",@LONG
你爬了約有兩層樓高的竹梯, 終於來到了這個向雲雙樓之一的觀暮
塔, 因為這是專門給賓客觀賞日暮黃昏的美好景色的一個高塔, 所以也
有佈置了小桌小椅, 供賓客座著好好品茶, 觀望風景. 除此之外, 此塔
居高臨下, 也可以讓向雲堂的人提早發現外敵入侵, 所以也有一些護衛
在此看守著.
LONG
    );
 set("exits",([ "down":__DIR__"inroom6",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
