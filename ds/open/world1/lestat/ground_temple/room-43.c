#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", HIR"五行迷魂陣"NOR) ;
        set( "long", @LONG
進入這裡後，你發現你迷路了！四周的景象一直不斷變化，讓你
不知道你身在何處，連進來時的入口都消失了，如果一直找不到離開
這裡的路，你可能得在這邊待一輩子了。
LONG
);
        set("hide_exits", ([ /* sizeof() == 7 */
                  "east" : __DIR__"room-41",
                  "west" : __DIR__"room-42",
                  "north" : __DIR__"room-37",
                  "south" : __DIR__"room-40",
                  "northeast" : __DIR__"room-35",
                  "northwest" : __DIR__"room-44",
                  "southwest" : __DIR__"room-39",
        ]));
        set("objects",([
                   __DIR__"../npc/nohead_ghost" : 1,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}



