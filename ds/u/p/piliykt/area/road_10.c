inherit ROOM;

void create()
{

set("short","東大街");
set("long", @LONG
你走在一條繁忙的街道上, 來往的過路人很多, 這裡已經是神木村的
東邊, 雖然沒有中央廣場那麼熱鬧, 但這裡還是神木村的中心範圍內, 你
還是可以看到很多商店和參光的客人.
LONG
);
set("outdoors", "land");
set("exits", ([                
        "west" : __DIR__"road_6.c", 
        "east" : __DIR__"rr_1.c", 
        ]));

 setup();
}

