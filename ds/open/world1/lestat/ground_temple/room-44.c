#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "地底洞穴") ;
        set( "long", @LONG
好不容易走出了可怕的五行迷魂陣，逃離了那堆惡鬼的追殺，你
來到了一條筆直而寬闊的通道，向北邊延伸而去的通道，幾乎看不到
盡頭，但是一陣陣強烈的魔法波動，卻一直源源不絕地傳來。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-45",
                  "south" : __DIR__"room-42",                  
        ]));
        set("objects",([
                   __DIR__"../npc/s_soldier" : 2,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}
