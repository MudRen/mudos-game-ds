inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  //"north" : __DIR__"room36", 
  //"south" : __DIR__"room40", 
  "east" : __DIR__"room38", 
  //"west" : __DIR__"room39",
]));
set("light",1);

        setup();
}

