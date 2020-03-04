inherit ROOM;

void create()
{
        set("short", "仙界");
        set("long", @long
仙界是一處與世無爭的世外桃源，也是眾人心中所嚮往的生活地
。在這裡聽不到爭吵、喧嘩，只有聽到人們充滿著快樂的聲音，過著
消遙自在的日子，在不遠的前方有著一片湖，四周的青山倒映在水中
，在湖面上有艘小船，少女們一陣輕柔婉轉的歌聲，飄在水濛濛的湖
面上，宛如人世間最美的一幅畫。

long);
        set("exits", ([
  "southwest" : __DIR__"ladd-2",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}

