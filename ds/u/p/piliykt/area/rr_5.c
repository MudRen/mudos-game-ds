inherit ROOM;
void create()
{

set("short","道路");
set("long", @LONG
這裡的道路沒有像神木村如此寬大, 這裡已經算是出了神木村, 因此
來往的人變的比較少, 往東邊可到達海邊.
LONG
);
set("outdoors", "land");
set("exits", ([                
"east" : __DIR__"rr_6.c", 
"west" : __DIR__"rr_3.c", 
        ]));

 setup();
}

