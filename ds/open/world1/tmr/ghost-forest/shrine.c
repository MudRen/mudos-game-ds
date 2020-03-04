// Room: /tmr/garea/shrine.c

inherit ROOM;
void create()
{
        set("short", "祭鬼祠");
        set("long", @LONG
你在一間不大的廟祠，傳聞鬼斷森林中早在數十年前就被一群鬼怪佔
據，此間廟祠就是用來祭祀，以求平安。前方有座黃銅香爐，裡頭尚點著
三柱大香，香爐後方擺設著一座八尺高的大石像。
LONG
        );
        set("no_clean_up", 0);
        set("objects",([
        __DIR__"npc/statue":1,
        ]) );
        set("light",1);
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"forest13",
        ]));

        setup();
}

void reset() // added by Cominging
{
        object statue;
        statue = present("ghost statue", this_object());
        if( statue )
                if( statue->query_ghost() )
                        return;
        ::reset();
}

