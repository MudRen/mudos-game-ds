inherit ROOM;

void create()
{

set("short","道路");
set("long", @LONG
你正在神木村的道路上, 這裡看起來沒有大街的熱鬧, 不過還是有些
許的商店, 往西邊好像有個房屋, 使你有了好奇心想去逛逛. 往北可到大
街.  
LONG
);
set("outdoors", "desert");
set("exits", ([                
        "south" : __DIR__"road_1.c", 
        "north" : __DIR__"road_3.c",
        "enter"  : __DIR__"horse_1.c",
   ]));

 setup();
}



