inherit ROOM;

void create()
{

set("short","南大街");
set("long", @LONG
這裡是神木村南邊的街道, 筆直的橫貫整個村莊, 北邊可到神木村
的大廣場，往北有間客棧.
LONG
);
set("no_clean_up", 0);
set("outdoors","land");
set("exits", ([                
        "south" : __DIR__"road_12.c", 
        "north" : __DIR__"road_8.c",
   ]));

 setup();
}

