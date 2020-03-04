inherit ROOM;

void create()
{
        set("short", "錟都的街道");
        set("long", @LONG
走在這裡你可以感到錟都城的生命力，這裡到處有小販在叫賣，往來
的路上川流不息，人來人往的好不熱鬧。不過也許你並不知道，在這往來
的人群到底有有多少人是小偷吧。
LONG
        );
        set("exits", ([                 
                "south" : __DIR__"city14",
                "east" : __DIR__"city21",
                "west" : __DIR__"city19",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/man":2 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

