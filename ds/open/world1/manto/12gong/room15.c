inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向天蠍宮的路上，只見前面可以看到美麗的天蠍宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的天坪宮。
LONG);

        set("exits", ([
            "northdown"    :       __DIR__"libra",
           "south"  :       __DIR__"room16",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(3),
        __DIR__"npc/fighter03" : 1+random(2),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

