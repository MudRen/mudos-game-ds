#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"森林"NOR);

 set("long",@LONG
傳說在這個森林深處有一棵松樹, 其樹齡已近七千, 且高大
無比, 但見過之人只有天梟攻丹一派的採藥者, 但尉遲妄霸佔此
處後不准天梟攻丹一派來此, 因此這棵參天古木已多年不再流傳
於藥界....
LONG
    );
 set("exits",([ "north":__DIR__"tree2",
                 "southwest":__DIR__"bird6",
    ]));
set("no_clean_up",0);
set("outdoors","forest");
 setup();
}

int valid_leave(object me, string dir)
{
       if( dir=="southwest" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

