inherit ROOM;
void create()
{
set("short","神木");
set("long", @LONG
你正站在巨大的樹枝上, 你的上方傳來了些許的聲音, 讓你不竟的想
到上頭去瞧瞧, 你的四周佈滿了樹枝.
LONG
);
set("outdoors", "desert");
set("exits", ([ 
                "down"  : __DIR__"tree.c",
                "east"  : __DIR__"tree2.c",                                
                           ]));
 setup();
}

