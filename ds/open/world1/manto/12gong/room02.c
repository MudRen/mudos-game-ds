inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向白羊宮的路上，只見前面可以看到美麗的白羊宮聳立在奧林
匹亞峰上！
LONG);
        set("exits", ([
           "east"    :       __DIR__"baiyang",
           "southwest"    :       __DIR__"room01",
        ]));

        set("chance",40);
        set("mob_amount",30);
        set("objects", ([
        __DIR__"npc/fighter01" : random(3),
        __DIR__"npc/fighter02" : random(2),
        ]));
        set("outdoors", "12gong");
        setup();
}

