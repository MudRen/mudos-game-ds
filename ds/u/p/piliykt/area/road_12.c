inherit ROOM;

void create()
{

set("short","道路");
set("long", @LONG
這裡是神木村南邊的小道路, 這裡的路明顯的比剛剛的大街, 還要難
走往南的道路就出了神木村, 往北可到達神木村中央廣場.
LONG
);
set("outdoors","land");
set("exits", ([                
        "south" : __DIR__"zz_1.c", 
        "north" : __DIR__"road_9.c",
   ]));

 setup();
}

