inherit ROOM;

void create()
{

set("short","小階梯");
set("long", @LONG
無砂鎮就在你前方幾公尺不遠處, 這裡的道路也較平坦, 比剛當山路
好走多了, 你可以見到有幾個旅人正在休息. 
LONG
);
set("outdoors","land");
set("exits", ([                
        "north" : __DIR__"cc_10.c", 
        "southup" : __DIR__"cc_8.c",
   ]));

 setup();
}

