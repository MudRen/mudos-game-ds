inherit ROOM;

void create()
{
        set("short", "武器之屋");
        set("long", @long

穿過了一個拱門，你到達了武器之屋。一到了這裡，你不禁被整
屋子的武器嚇了一大跳。這裡的武器不但數量多，種類之多也是令人
眼花撩亂，可以說是應有盡有。

long);
        set("exits", ([
  "northeast" : __DIR__"ladder-1",
]));
        set("objects", ([ 
  __DIR__"item/weapon_box.c" : 1,
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}
