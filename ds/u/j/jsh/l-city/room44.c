inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room46", 
  "northwest" : __DIR__"room45", 
  "east" : __DIR__"room43", 
  //"west" : __DIR__"room44",
]));
set("light",1);

        setup();
}

