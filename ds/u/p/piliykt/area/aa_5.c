inherit ROOM;

void create()
{

set("short","長廊走道");
set("long", @LONG
這一條長廊, 筆直的往東邊通去, 你偶爾可以聽到一些聲音, 讓你好
奇的想去看一看到底怎麼回事.
LONG
);
set("light",1);
set("exits", ([               
         
         "west" : __DIR__"aa_2.c", 
         "east" : __DIR__"aa_9.c", 
   ]));

set("objects",([
__DIR__"npc/guard_3.c" : 1,
              ]) );

setup();
}

