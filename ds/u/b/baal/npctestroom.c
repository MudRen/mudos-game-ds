#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"活物房"NOR);

 set("long",@LONG
這裡是索思的活物房, 顧名思義, 有很多活物的地方, 全都是索思黑
魔法下的產物, 四處血跡斑斑, 一股腥臭味瀰漫在此間...

LONG
    );
 set("exits",([ "up" : __DIR__"workroom2",
    ]));
        set("objects", ([ 
          __DIR__"area/dst/npc/poorguard" : 1,
          __DIR__"area/dst/npc/skeguard1" : 5,
          __DIR__"weapon/helldog" : 5,
        ]));

        set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
 

}
