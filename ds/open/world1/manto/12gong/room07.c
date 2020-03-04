inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向巨蟹宮的路上，只見前面可以看到美麗的巨蟹宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的雙子宮。
LONG);


        set("exits", ([
            "eastdown"  :       __DIR__"genini",
             "west"    :       __DIR__"room08",
        ]));
        set("chance",50);
        set("mob_amount",30); 
        set("objects", ([
        __DIR__"npc/fighter01" : random(2),
        __DIR__"npc/fighter02" : random(3),
        __DIR__"npc/fighter03" : random(2),
        ]));
        set("mob_object",({
        }) );
        set("outdoors", "12gong");
        setup();
}

