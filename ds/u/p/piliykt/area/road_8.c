inherit ROOM;

void create()
{

set("short","南大街");
set("long", @LONG
這裡的人比北邊較少, 但還是有些來往的過路人來到這, 因為東邊有
家客棧, 專門讓人過夜休息, 還有賣些雜用品和食物, 門口的匾額上頭寫
著「醉仙客棧」往南到達大街.
LONG
);
set("light",2);
set("outdoors","land");
set("exits", ([                
        "south" : __DIR__"road_9.c", 
        "east"  : __DIR__"homeroad_1.c",
        "north" : __DIR__"road_7.c",
   ]));

 setup();
}

