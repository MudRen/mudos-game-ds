inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
跨過了門檻，你走進了一棟民宅內，裡面的佈置十分的樸素，從備蛀
蟲蛀持掉的桌椅和門檻，以及堆放在角落的農具和斗笠，你知道這家是個
莊稼人，而屋裡的男人都以經出去種田了，只剩婦人在打掃家里，和小孩
在地上玩。

LONG
        );
        set("exits", ([                 
                "north" : __DIR__"city20",
                                        ]));

        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/yang":1 ,
                                            ]));           

                
        set("no_magic", 0);
        set("no_clean_up", 0);
        set("valid_startroom", 0);
        set("no_fight", 0);

        setup();
        replace_program(ROOM);
        
}

