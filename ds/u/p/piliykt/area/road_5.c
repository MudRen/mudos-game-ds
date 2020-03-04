inherit ROOM;

void create()
{

set("short","大街");
set("long", @LONG
你站在一條寬大的街道上, 這裡非常的熱鬧, 因為這裡是神木村的重
要道路, 這裡有許些坐臥在地上的乞丐, 他們正在向人乞討東西吃, 往北
邊有家藥鋪.往東到市中心.
LONG
);
set("outdoors", "desert");

set("exits", ([                
         "west" : __DIR__"road_4.c", 
         "north": __DIR__"shop_1.c",       
         "east" : __DIR__"road_6.c",
   ]));
set("objects",([
__DIR__"npc/mob_3.c" : 1,
       ]) );

 setup();
}

