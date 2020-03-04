inherit ROOM;

void create()
{

set("short","中央廣場");
set("long", @LONG
這裡就是神木村的中央廣場, 也是最熱鬧的地方, 這裡到處都是人影
, 擠的水洩不通, 好不熱鬧, 有很多人在這裡逛街, 有些小販到處販賣些
物品, 往南有間客棧, 讓來往的過路人休息, 往東走到底可到海邊, 往北
是條大街.
LONG
);
set("outdoors", "desert");
set("light",1);
set("exits", ([                
        "west" : __DIR__"road_5.c", 
        "east" : __DIR__"road_10.c", 
        "south" : __DIR__"road_7.c", 
        "north" : __DIR__"road_11.c", 
   ]));
set("objects",([
__DIR__"npc/guard_2.c" : 2,
       ]) );
 setup();
}

