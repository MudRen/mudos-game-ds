inherit ROOM;

void create()
{

set("short","道路");
set("long", @LONG
這裡是神木村往外的小道路, 這裡的路開始變的越來越不好走, 走的
你雙腳都磨出水泡, 兩旁的風景迷人, 讓你看得忘了你現在要去哪, 往南
可以到達神木村往北通往無砂鎮.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "south" : __DIR__"road_13.c", 
        "northup" : __DIR__"cc_2.c",
   ]));
set("objects",([
__DIR__"npc/dog1.c" : 1,
       ]) );
 setup();
}



