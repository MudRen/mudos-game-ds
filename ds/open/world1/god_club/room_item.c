inherit ROOM;

void create()
{
        set("short", "道具之屋");
        set("long", @long
道具之屋，顧名思義就是專門放置道具的地方。不過這裡可不比
一般的道具之屋，這裡除了一些稀鬆平常的道具之外，還有著許多世
間罕見的稀世珍品。

long);
        set("exits", ([
  "north" : __DIR__"boardroom",
]));
        set("objects", ([ 
  __DIR__"item/item_box.c" : 1,
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}

