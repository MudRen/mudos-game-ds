inherit ROOM;

void create()
{

set("short","道路");
set("long", @LONG
這裡是神木村北邊的小道路, 這裡的路開始變的崎嶇漸漸不好走, 在
你的前方有一條小道路, 好像是神木村往北的對外道路, 聽說可以連接到
海港無砂鎮.
LONG
);
set("outdoors","land");
set("exits", ([                
        "south" : __DIR__"road_11.c", 
        "north" : __DIR__"cc_1.c",
   ]));

 setup();
}

