inherit ROOM;

void create()
{

set("short","小道路");
set("long", @LONG
這裡是大神木旁的小路, 路邊有很多的田地, 你可以看見有很多的
農夫在辛苦的耕田, 往西有棵大樹.     
LONG
);
set("outdoors", "land");


set("exits", ([ 
      
      "west" : __DIR__"big_tree.c",
      "north" : __DIR__"road_2.c", 
       
    ]));
set("objects",([
__DIR__"npc/mob_1.c" : 2,
       ]) );
setup();
}

