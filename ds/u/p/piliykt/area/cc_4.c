inherit ROOM;

void create()
{

set("short","大石堆");
set("long", @LONG
你來到這觀察了一下四周, 發現你的周圍都是石頭, 大大小小的石頭
堆在地上不知有甚麼意義.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "south" : __DIR__"cc_3.c", 
        "north" : __DIR__"cc_5.c",
   ]));

 setup();
}

