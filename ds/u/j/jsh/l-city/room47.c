inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room49", 
  //"northeast" : __DIR__"room44", 
  "east" : __DIR__"room45", 
  //"west" : __DIR__"room48",
]));
set("light",1);

        setup();
}

