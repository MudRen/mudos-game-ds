inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"south" : __DIR__"room23", 
  "south" : __DIR__"room25", 
  "east" : __DIR__"room23",
]));
set("light",1);

        setup();
}

