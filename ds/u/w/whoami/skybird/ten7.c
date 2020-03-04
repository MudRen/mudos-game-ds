#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","滅骨峰");

 set("long",@LONG
這裡是滅骨峰的北部, 你看到有一個劍碑在這裡, 想來是為
了紀念胡育的生平事蹟, 話說回來, 如果從這裡再往北行約數十
丈, 就會進入十萬大山中最迂迴曲折的羊腸道了.
LONG
    );
 set("exits",([ "eastup":__DIR__"ten8",
                "southdown":__DIR__"ten2",
    ]));
 set("item_desc",([
        "劍碑":"你看到上面寫著: 胡育, 年四三而逝, 一生行俠仗義, 降敵無數.... 哇! 下面看不清楚了....\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

