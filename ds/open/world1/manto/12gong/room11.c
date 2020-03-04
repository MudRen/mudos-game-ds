inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG

這是走向處女宮的路上，只見前面可以看到美麗的處女宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的獅子宮。
LONG);


        set("exits", ([
            "north"    :       __DIR__"room12",
            "westdown"  :       __DIR__"leo",
        ]));
        set("chance",60);
        set("mob_amount",30); 
        set("objects", ([
        __DIR__"npc/fighter01" : random(2),
        __DIR__"npc/fighter02" : random(2),
        __DIR__"npc/fighter03" : random(3),
        ]));
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

