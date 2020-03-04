inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向天坪宮的路上，只見前面可以看到美麗的天坪宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的處女宮。
LONG);

        set("exits", ([
            "southeast"    :       __DIR__"libra",
           "west"  :       __DIR__"room13",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : 1+random(2),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("outdoors", "12gong");
        setup();
}

