inherit ROOM;

void create()
{

set("short","西大街");
set("long", @LONG
你正站在西大街上, 這裡兩旁有很多的商店和攤販, 向你販售物品
, 讓你眼光撩亂.往東到達大街. 往南有條道路.
LONG
);
set("outdoors", "desert");
set("exits", ([            
         "south": __DIR__"road_2.c",       
         "east" : __DIR__"road_4.c",
   ]));
set("objects",([
__DIR__"npc/mob_2.c" : 1,
       ]) );

 setup();
}

