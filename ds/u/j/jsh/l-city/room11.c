inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room12", 
  "east" : __DIR__"room10", 
  //"west" : __DIR__"room11",
]));
set("light",1);

        setup();
}

