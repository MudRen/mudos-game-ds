inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room23", 
  "northeast" : __DIR__"room3", 
  //"east" : __DIR__"room14",
]));
set("light",1);

        setup();
}

