inherit ROOM;

void create()
{

set("short","山中小路");
set("long", @LONG
你走在這崎嶇的山路上, 小石頭佈滿了整條山路, 走到你腳底發軟四
肢無力, 癱倒在地, 你往前一看, 才知道無砂鎮就在山腳的前方.
LONG
);
set("outdoors","forest");
set("exits", ([                
        "south" : __DIR__"cc_4.c", 
        "east" : __DIR__"cc_6.c",
   ]));

 setup();
}

