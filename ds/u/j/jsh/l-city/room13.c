inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room12", 
  //"north" : __DIR__"room13", 
  "east" : __DIR__"room14",
]));
set("light",1);

        setup();
}

