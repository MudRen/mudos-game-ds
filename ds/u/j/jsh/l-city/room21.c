inherit ROOM;

void create()
{
        set("short", "�L��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"room20", 
  //"northeast" : __DIR__"room21", 
  //"east" : __DIR__"room17",
  //"west" : __DIR__"room17",
]));
set("light",1);

        setup();
}

