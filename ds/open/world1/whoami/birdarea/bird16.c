#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"客房");

 set("long",@LONG
這裡是專門給信徒住的客房, 一共有三張床, 房中有一個給
信徒膜拜的天梟石像, 還有一個照顧這些信徒的小弟, 雖然是小
弟, 但是看他打掃的樣子, 就知道他也會武功。
LONG
    );
 
 set("exits",(["north":__DIR__"bird15",
    ]));
 set("objects",([__DIR__"npc/man" : 2+random(2),
                 __DIR__"npc/waiter":1,
     ]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           

