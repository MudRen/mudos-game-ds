inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
這是走向寶瓶宮的路上，只見前面可以看到美麗的寶瓶宮聳立在奧林
匹亞峰上！雲霧中隱隱約約還可以看見山下的魔羯宮。
LONG);

        set("exits", ([
            "east"    :       __DIR__"room22",
            "westdown"  :       __DIR__"capricorn",
        ]));
        set("objects", ([
        __DIR__"npc/fighter02" : 1+random(2),
        __DIR__"npc/fighter03" : 1+random(3),
        ]));
        set("chance",60);
        set("mob_amount",20);
        set("mob_object",({
            }) );
        set("outdoors", "12gong");
        setup();
}

