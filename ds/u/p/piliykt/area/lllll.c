inherit ROOM;
void create()
{
set("short","山縫");
set("long", @LONG
你正站在山縫裡, 這裡由於是山縫, 所以空隙很小, 也許是空氣不流
通, 讓你覺得這裡可能是一座火山, 因為這裡的溫度熱到你受不了, 你不
竟想快點逃離這裡.
LONG
);
set("outdoors","heat");
set("exits", ([ 
                "south"  : __DIR__"tree5.c",
                           ]));
set("objects",([
__DIR__"npc/master_2.c" : 1,
              ]) );
setup();
        
}

