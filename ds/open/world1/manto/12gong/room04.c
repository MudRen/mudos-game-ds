inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向金牛宮的路上，只見前面可以看到美麗的金牛宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的白羊宮。
LONG);

        set("exits", ([
         "southeast"    :       __DIR__"taurus",
         "west"    :       __DIR__"room03",
        ]));
        set("chance",40);
        set("mob_amount",30);
        set("objects", ([
        __DIR__"npc/fighter01" : random(3),
        __DIR__"npc/fighter02" : random(3),
        ]));
        set("mob_object",({
        }) );

        set("outdoors", "12gong");
        setup();
}

