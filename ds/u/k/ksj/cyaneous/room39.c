inherit ROOM;

void create()
{
        set("short", "商店街－武器店");
        set("long", @LONG
這裡是港都商店街中的武器店，店門口上方掛著兩把刀劍，店裡則是擺滿了
    明晃晃的刀劍武器，其中有些還是你見都沒見過的，店裡的生意很好，不論
    平民、武者、各行各業都會到這邊來挑選些武器。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room38",
  "southwest" : __DIR__"room42",
  "north" : __DIR__"room35",
  "east" : __DIR__"room40",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

