inherit ROOM;

void create()
{
        set("short", "武器店");
        set("long", @LONG
這裡是港都商店街中的武器店，店門口上方掛著兩把刀劍，店裡則是擺滿了
明晃晃的刀劍武器，其中有些還是你見都沒見過的，店裡的生意很好，不論平民
、武者、各行各業都會到這邊來挑選些武器。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "west" : __DIR__"room4", 
  "south": __DIR__"room8",
  //"north": __DIR__"room4", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


