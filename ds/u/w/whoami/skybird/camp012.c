inherit ROOM;

void create()
{
        set("short", "固山寨");
        set("long", @LONG
軍營中門大開，營中崗哨林立，弓上弦，刀出銷，一股殺氣
撲面而來，你不由更為緊張。看到你等前來，營中的士兵依舊若
無其事，各自忙著自已的事，看到軍紀如此嚴明，你不由心中一
震。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"camp016",
  "west" : __DIR__"camp009",
  "north" : __DIR__"camp011",
  "south" : __DIR__"camp013",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

