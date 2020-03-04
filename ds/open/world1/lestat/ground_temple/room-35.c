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
        set("hide_exits", ([ /* sizeof() == 6 */
                  "east" : __DIR__"room-36",
                  "west" : __DIR__"room-37",
                  "north" : __DIR__"room-38",
                  "south" : __DIR__"room-41",
                  "northeast" : __DIR__"room-39",
                  "southwest" : __DIR__"room-43",
                  "southeast" : __DIR__"room-34",
        ]));
        set("objects",([
                   __DIR__"../npc/hungry_ghost" : 2,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}


