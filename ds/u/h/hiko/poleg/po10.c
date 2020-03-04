inherit ROOM;
void create()
{
        set("short", "泊浪村廣場");        
        set("long",@LONG
你來到泊浪村的廣場，看來有不少人在此地，看他們的神情好像是
在討論什麼事，北邊是通往漁會頭目家，泊浪村的漁會頭目聽說是受過
高人指點，而東邊是往泊浪村長家，往南邊是一些民宅，也許當中會臥
虎藏龍有著高人。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po11",
  "west" : __DIR__"po9" ,  
  "east" : __DIR__"po16",
  "south" : __DIR__"po13",
]));
      set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/villager" : 4,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}







