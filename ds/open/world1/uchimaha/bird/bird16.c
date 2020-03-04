#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","客房");

 set("long",@LONG
這裡是專門給信徒住的客房, 一共有三張床, 房中
有一個給信徒膜拜的天梟石像, 還有一個照顧這些信徒
的小弟, 雖然是小弟, 但是看他打掃的樣子, 就知道他
也會武功。

LONG
    );
 
 set("exits",(["north":__DIR__"bird15",
    ]));
 set("objects",([__DIR__"npc/man" : 3,
                 __DIR__"npc/waiter":1,
     ]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           
