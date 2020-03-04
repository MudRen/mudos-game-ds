#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","黃土小路");

 set("long",@LONG
從這裡已經可以看到山寨的大門的, 如果你武功不高, 且存
心不想活了, 不要緊, 繼續往裡面走吧! 但是如果你武功高強,
滿腔熱血, 想把山賊殺得雞飛狗跳, 就可以得到正道的推崇...
LONG
    );
 set("exits",([ "southwest":__DIR__"ten4",
                "east":__DIR__"ten6",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

